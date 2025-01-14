// -----------------------------------------------------------------------
// De math3d.cpp
// -----------------------------------------------------------------------
#include "MapMath.h"
#include <math.h>

typedef struct AUGMENTEDMATRIXTAG
{
	float rowA[4];
	float rowB[4];
	float rowC[4];
	float *pRow1;
	float *pRow2;
	float *pRow3;
} augmatrix;

typedef struct
{
	float columnA[3];
	float columnB[3];
	float columnC[3];
	float columnD[3];
	float *pCol1;
	float *pCol2;
	float *pCol3;
	float *pCol4;
} augmatrix_columns;



#define EPSILON 1e-5f
// -----------------------------------------------------------------------
void VectorCopy(float *b,float *a)
{
	b[0]=a[0];
	b[1]=a[1];
	b[2]=a[2];
}
// -----------------------------------------------------------------------
void VectorScale(float scale,float *a, float *b)
{
#ifdef _USE3DNOW_
	_asm
	{
		femms
		mov		eax, dword ptr [a]
		mov		edx, dword ptr [b]
		movd	mm0,scale
		movq	mm1,[eax]
		punpckldq	mm0,mm0
		movd	mm2,[eax+8]
		pfmul	(m1,m0)
		pfmul	(m2,m0)
		movq	[edx],mm1
		movd	[edx+8],mm2
		femms
		
	}
#else
	b[0]=scale*a[0];
	b[1]=scale*a[1];
	b[2]=scale*a[2];
#endif
}
// -----------------------------------------------------------------------
void VectorSubtract(float *a,float *b,float *c)
{
#ifdef _USE3DNOW_
	_asm
	{
		femms
		mov		eax, dword ptr [a]
		mov		edx, dword ptr [b]
		movq	mm0, [eax]
		movd	mm1, [eax+8]
		pfsub	(m0, edx)
		movd	mm2, [edx+8]
		pfsub	(m1,m2)
		mov		eax, dword ptr [c]
		movq	[eax],mm0
		movd	[eax+8],mm1
		femms
	}

#else
	c[0]=a[0]-b[0];
	c[1]=a[1]-b[1];
	c[2]=a[2]-b[2];
#endif
}
// -----------------------------------------------------------------------
float DotProd(float *a,float *b)
{
#ifdef _USE3DNOW_
	float c1;
	_asm
	{
		femms
		mov		eax, dword ptr [a]
		mov		ebx, dword ptr [b]
		movq    mm0, [eax]
		movd	mm1, [eax+8]
		pfmul	(m0,ebx)
		pfmulm	(m1,ebx,8)
		pfacc	(m0,m1)
		pfacc	(m0,m0)
		movd	c1, mm0
		femms
	}
	return c1;
#else
	return(a[0]*b[0]+a[1]*b[1]+a[2]*b[2]);
#endif
}
// -----------------------------------------------------------------------
void MakeNormalized(float *v)
{
#ifdef _USE3DNOW_
	_asm
	{
		femms
		mov	eax, dword ptr [v]
		movq	mm0, [eax]
		movq	mm3, mm0
		pfmul	(m0,m0)
		movd	mm1, [eax+8]
		movq	mm4, mm1
		pfmul	(m1,m1)
		pfacc	(m0,m0)
		pfadd	(m0,m1)
		pfrsqrt (m1,m0)
		movq	mm2,mm1
		pfmul	(m2,m2)
		pfrsqit1 (m2,m0)
		pfrcpit2 (m2,m1)
		punpckldq mm2,mm2
		pfmul	(m3,m2)
		movq	[eax],mm3
		pfmul	(m4,m2)
		movd	[eax+8],mm4
		femms
	}
#else	
	float d;

	d=(float)sqrt((double)DotProd(v,v));
	if(d<EPSILON)
	{
		v[0]=0;
		v[1]=0;
		v[2]=0;
		return;
	}
	VectorScale(1/d,v,v);
#endif
}
// -----------------------------------------------------------------------
int PlaneType(float *norm)
{
	float n[3];
	float ax,ay,az;
	VectorCopy(n,norm);
	MakeNormalized(n);
	int type=0;

	if (n[0] == 1.0 || n[0] == -1.0)
	{
		type=0;
		goto returntype;
	}
	if(n[1] == 1.0 || n[1] == -1.0)
	{
		type=1;
		goto returntype;
	}
	if(n[2] == 1.0 || n[2] == -1.0)
	{
		type=2;
		goto returntype;
	}
		
	ax = (float)fabs((double)n[0]);
	ay = (float)fabs((double)n[1]);
	az = (float)fabs((double)n[2]);
	
	if(ax >= ay && ax >= az)
	{
		type=3;
		goto returntype;

	}
	if(ay >= ax && ay >= az)
	{
		type=4;
		goto returntype;
	}
	type=5;
returntype:
	return type;
}
// -----------------------------------------------------------------------
void InitializeAugMatrix(augmatrix *pm)
{
	pm->pRow1=pm->rowA;
	pm->pRow2=pm->rowB;
	pm->pRow3=pm->rowC;
}
// -----------------------------------------------------------------------
void AugmatrixToAugmatrixColumn(augmatrix_columns *dest, augmatrix *source)
{
	dest->pCol1=dest->columnA;
	dest->pCol2=dest->columnB;
	dest->pCol3=dest->columnC;
	dest->pCol4=dest->columnD;
	dest->columnA[0]=source->pRow1[0];
	dest->columnA[1]=source->pRow2[0];
	dest->columnA[2]=source->pRow3[0];
	dest->columnB[0]=source->pRow1[1];
	dest->columnB[1]=source->pRow2[1];
	dest->columnB[2]=source->pRow3[1];
	dest->columnC[0]=source->pRow1[2];
	dest->columnC[1]=source->pRow2[2];
	dest->columnC[2]=source->pRow3[2];
	dest->columnD[0]=source->pRow1[3];
	dest->columnD[1]=source->pRow2[3];
	dest->columnD[2]=source->pRow3[3];
}
// -----------------------------------------------------------------------
float Determinate(float *c1,float *c2, float *c3)
{
	float t;
	t=c1[0]*(c2[1]*c3[2]-c3[1]*c2[2]);
	t-=c2[0]*(c1[1]*c3[2]-c3[1]*c1[2]);
	t+=c3[0]*(c1[1]*c2[2]-c2[1]*c1[2]);

	t-=c1[1]*(c2[0]*c3[2]-c3[0]*c2[2]);
	t+=c2[1]*(c1[0]*c3[2]-c3[0]*c1[2]);
	t-=c3[1]*(c1[0]*c2[2]-c2[0]*c1[2]);

	t+=c1[2]*(c2[0]*c3[1]-c3[0]*c2[1]);
	t-=c2[2]*(c1[0]*c3[1]-c3[0]*c1[1]);
	t+=c3[2]*(c1[0]*c2[1]-c2[0]*c1[1]);

	return t;
}
// -----------------------------------------------------------------------
bool SolveMatrix(CPlane &p1,CPlane &p2,CPlane &p3,CVect3 &_roSol)
{
	static augmatrix			m;
	static augmatrix_columns	d;
	float fDM;
	float fInvDM;

	m.rowA[0] = p1.Normal().X();
	m.rowA[1] = p1.Normal().Y();
	m.rowA[2] = p1.Normal().Z();
	m.rowA[3] = p1.D();

	m.rowB[0] = p2.Normal().X();
	m.rowB[1] = p2.Normal().Y();
	m.rowB[2] = p2.Normal().Z();
	m.rowB[3] = p2.D();

	m.rowC[0] = p3.Normal().X();
	m.rowC[1] = p3.Normal().Y();
	m.rowC[2] = p3.Normal().Z();
	m.rowC[3] = p3.D();
	
	InitializeAugMatrix(&m);
	
	AugmatrixToAugmatrixColumn(&d,&m);

	fDM = Determinate(d.pCol1,d.pCol2,d.pCol3);
	if (fDM==0.0f) return false;
	fInvDM = 1.0f / fDM;

	_roSol.SetX( Determinate(d.pCol4, d.pCol2, d.pCol3) * fInvDM );
	_roSol.SetY( Determinate(d.pCol1, d.pCol4, d.pCol3) * fInvDM );
	_roSol.SetZ( Determinate(d.pCol1, d.pCol2, d.pCol4) * fInvDM );

	return true;
}
// -----------------------------------------------------------------------