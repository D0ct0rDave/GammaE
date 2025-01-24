// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
// #ifndef CGVECTORH // done on purpose
// #define CGVECTORH // done on purpose
// ----------------------------------------------------------------------------
class CGVECTOR
{
    public:
        CGVECTOR()
        {
        }
        CGVECTOR(
            float _fX,
            float _fY

            #if defined(HAS_Z)
            ,float _fZ
            #endif

            #if defined(HAS_W)
            ,float _fW
            #endif
            );

        void Set(
            float _fX,
            float _fY

            #if defined(HAS_Z)
            ,float _fZ
            #endif

            #if defined(HAS_W)
            ,float _fW
            #endif
            );

        void Point(float _fAzimut, float _fElevation);

        void Assign(const CGVECTOR& _oV);

        void CrossProd(const CGVECTOR& _oV1,const CGVECTOR& _oV2);

        void Normal(const CGVECTOR& _oA, const CGVECTOR& _oB, const CGVECTOR& _oC);

        void Orthogonal(const CGVECTOR& _oV);

        void LineEq(const CGVECTOR& _oPos, const CGVECTOR& _oDir, float _fU);

        void Add(const CGVECTOR& _oV);

        void Sub(const CGVECTOR& _oV);

        void Mult(const CGVECTOR& _oV);

        void Scale(float _fFactor);

        void Add(
            float _fX,
            float _fY

            #if defined(HAS_Z)
            ,float _fZ
            #endif

            #if defined(HAS_W)
            ,float _fW
            #endif
            );

        void Sub(
            float _fX,
            float _fY

            #if defined(HAS_Z)
            ,float _fZ
            #endif

            #if defined(HAS_W)
            ,float _fW
            #endif
            );

        void Mult(
            float _fX,
            float _fY

            #if defined(HAS_Z)
            ,float _fZ
            #endif

            #if defined(HAS_W)
            ,float _fW
            #endif
            );

        float fDotProd(const CGVECTOR& _oV) const;

        void Interpolate(const CGVECTOR& _oA,const CGVECTOR& _oB, float _fFact);

        void Normalize();

        float fModule() const;

        float fSqModule() const;

        float fDistance(const CGVECTOR& _oPnt) const;

        float fSqDistance(const CGVECTOR& _oPnt) const;

        bool bInside(const CGVECTOR& _oMax, const CGVECTOR& _oMin) const;

        bool bEqual(const CGVECTOR& _oV) const;

        uint uiGetGreaterAxis() const;

        static const CGVECTOR& oZero()
        {
            return(_goZEROVECTOR);
        }

        static const CGVECTOR& oX()
        {
            return(_goXAXISVECTOR);
        }

        static const CGVECTOR& oY()
        {
            return(_goYAXISVECTOR);
        }

        #if defined (HAS_Z)
        static const CGVECTOR& oZ()
        {
            return(_goZAXISVECTOR);
        }
        #endif

        #if defined (HAS_W)
        static const CGVECTOR& oW()
        {
            return(_goWAXISVECTOR);
        }
        #endif

        // / Cannot use unnamed unions due to scripting issues :(
        float& v(uint _uiIdx) const
        {
            return( *( (float*)&x + _uiIdx ) );
        }

        const float* V() const
        {
            return(&x);
        }

        // float& operator[](const uint index) const;

        float x;
        float y;

        #ifdef HAS_Z
        float z;
        #endif

        #ifdef HAS_W
        float w;
        #endif

    private:

        static CGVECTOR _goZEROVECTOR;
        static CGVECTOR _goXAXISVECTOR;
        static CGVECTOR _goYAXISVECTOR;

        #if defined (HAS_Z)
        static CGVECTOR _goZAXISVECTOR;
        #endif

        #if defined (HAS_W)
        static CGVECTOR _goWAXISVECTOR;
        #endif
};
// ----------------------------------------------------------------------------
inline CGVECTOR::CGVECTOR(float _fX, float _fY
#ifdef HAS_Z
                          ,float _fZ
#endif

#ifdef HAS_W
                          ,float _fW
#endif
                          )
{
    x = _fX;
    y = _fY;

    #ifdef HAS_Z
    z = _fZ;
    #endif

    #ifdef HAS_W
    w = _fW;
    #endif
}

inline void CGVECTOR::Set(float _fX, float _fY
#ifdef HAS_Z
                          ,float _fZ
#endif

#ifdef HAS_W
                          ,float _fW
#endif
                          )
{
    x = _fX;
    y = _fY;

    #ifdef HAS_Z
    z = _fZ;
    #endif

    #ifdef HAS_W
    w = _fW;
    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Point(float _fAzimut, float _fElevation)
{
    static float c;
    c = (float)Math::fCos(_fElevation);

    x = c * Math::fCos(_fAzimut);
    y = c * Math::fSin(_fAzimut);

    #ifdef HAS_Z
    z = (float)Math::fSin(_fElevation);
    #endif

    #ifdef HAS_W
    w = 1.0f;
    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Assign(const CGVECTOR& _oV)
{
    x = _oV.x;
    y = _oV.y;

    #ifdef HAS_Z
    z = _oV.z;
    #endif

    #ifdef HAS_W
    w = _oV.w;
    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::CrossProd(const CGVECTOR& _oV1,const CGVECTOR& _oV2)
{
    #if defined(HAS_W)

    // Vect4 cross prod ???

    #elif defined(HAS_Z)

    x = _oV1.y * _oV2.z - _oV1.z * _oV2.y;
    y = _oV1.z * _oV2.x - _oV1.x * _oV2.z;
    z = _oV1.x * _oV2.y - _oV1.y * _oV2.x;

    #else

    // Vect2 cross prod ???

    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Normal(const CGVECTOR& _oA, const CGVECTOR& _oB, const CGVECTOR& _oC)
{
    CGVECTOR ba,ca;

    ba.Assign(_oB);
    ba.Sub(_oA);
    ca.Assign(_oC);
    ca.Sub(_oA);

    CrossProd(ba,ca);
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Orthogonal(const CGVECTOR& _oV)
{
    #if defined(HAS_W)

    // Vect4 orthogonal

    #elif defined(HAS_Z)

    float fX = Math::fAbs(_oV.x);
    float fY = Math::fAbs(_oV.y);
    float fZ = Math::fAbs(_oV.z);

    // Regla: intercambiar las 2 coordenadas con valores más altos
    // la coordenada que tenga menor valor se invierte ( multiplica por -1)
    // la coordenada con valor más bajo se deja a 0

    if ( fX > fY )
    {
        if ( fY > fZ )
        {
            // fX > fY && fY > fZ
            x = -_oV.y;
            y = _oV.x;
            z = 0.0f;
        }
        else
        {
            if ( fX > fZ )
            {
                // fX > fY && fX > fZ && fZ > fY
                x = -_oV.z;
                y = 0.0f;
                z = _oV.x;
            }
            else
            {
                // fX > fY && fZ < fX fY < fZ
                x = _oV.z;
                y = 0.0f;
                z = -_oV.x;
            }
        }
    }
    else
    {
        if ( fY > fZ )
        {
            if ( fX > fZ )
            {
                // fY > fX && fY > fZ && fX > fZ
                x = _oV.y;
                y = -_oV.x;
                z = 0.0f;
            }
            else
            {
                // fY > fX && fY > fZ && fZ > fX
                x = 0.0f;
                y = -_oV.z;
                z = _oV.y;
            }
        }
        else
        {
            // fZ > fY && fY > fX
            x = 0.0f;
            y = _oV.z;
            z = -_oV.y;
        }
    }

    #else

    // Vect2 orthogonal
    y = _oV.x;
    x = -1.0f * _oV.y;

    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::LineEq(const CGVECTOR& _oPos,const CGVECTOR& _oDir, float _fU)
{
    x = _oPos.x + _fU * _oDir.x;
    y = _oPos.y + _fU * _oDir.y;
    #ifdef HAS_Z
    z = _oPos.z + _fU * _oDir.z;
    #endif

    #ifdef HAS_W
    w = _oPos.w + _fU * _oDir.w;
    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Add(const CGVECTOR& _oV)
{
    x += _oV.x;
    y += _oV.y;

    #ifdef HAS_Z
    z += _oV.z;
    #endif

    #ifdef HAS_W
    w += _oV.w;
    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Sub(const CGVECTOR& _oV)
{
    x -= _oV.x;
    y -= _oV.y;

    #ifdef HAS_Z
    z -= _oV.z;
    #endif

    #ifdef HAS_W
    w -= _oV.w;
    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Mult(const CGVECTOR& _oV)
{
    x *= _oV.x;
    y *= _oV.y;

    #ifdef HAS_Z
    z *= _oV.z;
    #endif

    #ifdef HAS_W
    w *= _oV.w;
    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Scale(float _fFactor)
{
    x *= _fFactor;
    y *= _fFactor;

    #ifdef HAS_Z
    z *= _fFactor;
    #endif

    #ifdef HAS_W
    w *= _fFactor;
    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Add(
    float _fX,
    float _fY

#if defined(HAS_Z)
    ,float _fZ
#endif

#if defined(HAS_W)
    ,float _fW
#endif
    )
{
    x += _fX;
    y += _fY;

    #ifdef HAS_Z
    z += _fZ;
    #endif

    #ifdef HAS_W
    w += _fW;
    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Sub(
    float _fX,
    float _fY

#if defined(HAS_Z)
    ,float _fZ
#endif

#if defined(HAS_W)
    ,float _fW
#endif
    )
{
    x -= _fX;
    y -= _fY;

    #ifdef HAS_Z
    z -= _fZ;
    #endif

    #ifdef HAS_W
    w -= _fW;
    #endif
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Mult(
    float _fX,
    float _fY

#if defined(HAS_Z)
    ,float _fZ
#endif

#if defined(HAS_W)
    ,float _fW
#endif
    )
{
    x *= _fX;
    y *= _fY;

    #ifdef HAS_Z
    z *= _fZ;
    #endif

    #ifdef HAS_W
    w *= _fW;
    #endif
}
// ----------------------------------------------------------------------------
inline float CGVECTOR::fDotProd(const CGVECTOR& _oV) const
{
    return (
               x * _oV.x + y * _oV.y

               #ifdef HAS_Z
               + z * _oV.z
               #endif

               #ifdef HAS_W
               + w * _oV.w
               #endif
               );
}
// ----------------------------------------------------------------------------
inline float CGVECTOR::fModule() const
{
    return( Math::fSqrt( fSqModule() ) );
}
// ----------------------------------------------------------------------------
inline float CGVECTOR::fSqModule() const
{
    return (x * x + y * y

            #ifdef HAS_Z
            + z * z
            #endif

            #ifdef HAS_W
            + w * w
            #endif
            );
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Normalize()
{
    static float m;

    m = fModule();
    if ( m == 1 ) return;

    if ( m )
    {
        m = 1.0f / m;

        x *= m;
        y *= m;

        #ifdef HAS_Z
        z *= m;
        #endif

        #ifdef HAS_W
        w *= m;
        #endif
    }
    else
    {
        x = Math::fSign(x) * 1e07f;
        y = x;

        #ifdef HAS_Z
        z = x;
        #endif

        #ifdef HAS_W
        w = x;
        #endif
    }
}
// ----------------------------------------------------------------------------
inline void CGVECTOR::Interpolate(const CGVECTOR& _oA,const CGVECTOR& _oB, float _fFact)
{
    /*
       // x = a*(1-f) + b*f   =>   x = a -a*f + b*f    =>	x = a + (b-a)*f

       float *va = a.v;
       float *vb = b.v;
       float *vc = v;

     *vc  = *va+(*vb - *va)*Factor;va++;vb++;vc++;
     *vc  = *va+(*vb - *va)*Factor;va++;vb++;vc++;
     *vc  = *va+(*vb - *va)*Factor;
     */
    x = _oA.x + (_oB.x - _oA.x) * _fFact;
    y = _oA.y + (_oB.y - _oA.y) * _fFact;

    #ifdef HAS_Z
    z = _oA.z + (_oB.z - _oA.z) * _fFact;
    #endif

    #ifdef HAS_W
    w = _oA.w + (_oB.w - _oA.w) * _fFact;
    #endif
}
// ----------------------------------------------------------------------------
inline float CGVECTOR::fDistance(const CGVECTOR& _oPnt) const
{
    return ( Math::fSqrt( fSqDistance(_oPnt) ) );
}
// ----------------------------------------------------------------------------
inline float CGVECTOR::fSqDistance(const CGVECTOR& _oPnt) const
{
    static CGVECTOR VAux;

    VAux.Assign(*this);
    VAux.Sub  (_oPnt);

    return ( VAux.fSqModule() );
}
// ----------------------------------------------------------------------------
inline bool CGVECTOR::bInside (const CGVECTOR& _oMax,const CGVECTOR& _oMin) const
{
    return(
               (x >= _oMin.x) && (x <= _oMax.x)
               && (y >= _oMin.y) && (y <= _oMax.y)

               #ifdef HAS_Z
               && (z >= _oMin.z) && (z <= _oMax.z)
               #endif

               #ifdef HAS_W
               && (w >= _oMin.w) && (w <= _oMax.w)
               #endif
               );
}
// ----------------------------------------------------------------------------
inline bool CGVECTOR::bEqual(const CGVECTOR& _oV) const
{
    return(
               Math::bEqual(x,_oV.x)
               && Math::bEqual(y,_oV.y)

               #ifdef HAS_Z
               && Math::bEqual(z,_oV.z)
               #endif

               #ifdef HAS_W
               && Math::bEqual(w,_oV.w)
               #endif
               );
}
// ----------------------------------------------------------------------------
inline uint CGVECTOR::uiGetGreaterAxis () const
{
    #if defined(HAS_W)

    float fMax = x;
    uint uiMax = 0;
    float* elems = (float*)&x;

    for ( uint i = 1; i < 4; i++ )
    {
        if ( elems[i] > fMax )
        {
            fMax = elems[i];
            uiMax = i;
        }
    }

    return (uiMax);

    #elif defined(HAS_Z)

    if ( x > y )
    {
        if ( y > z )
            // x > y && y > z
            return(0);
        else
        {
            if ( x > z )
                // x > y && x > z
                return(0);
            else
                // x > y && z > x
                return(2);
        }
    }
    else
    {
        if ( y > z )
            // y > x && y > z
            return(1);
        else
            // z > y && y > z
            return(2);
    }

    #else

    if ( x > y )
        return(0);
    else
        return(1);

    #endif
}
// ----------------------------------------------------------------------------
// #endif // done on purpose
// ----------------------------------------------------------------------------
