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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "GammaE_E3D.h"
#include "ASE_ModelParser.h"

// -----------------------------------------------------------------------------
// Defines necesarios para el módulo
// -----------------------------------------------------------------------------
#ifndef MAX_CARS
    #define MAX_CARS 256
#endif
// -----------------------------------------------------------------------------
// Parsing states
// -----------------------------------------------------------------------------

#define STATE_Searching           0
#define STATE_Ready               1
#define STATE_Comenting1          2
#define STATE_Comenting2          3
#define STATE_Comenting3          4

// -----------------------------------------------------------------------------
// Token Table
// -----------------------------------------------------------------------------

#define TKTYPE_NUMVERTEX            0
#define TKTYPE_NUMTVERTEX           1
#define TKTYPE_NUMFACES             2

#define TKTYPE_TVERTEX              10
#define TKTYPE_VERTEX               11
#define TKTYPE_FACE                 12
#define TKTYPE_NORMAL               13

#define NUM_TOKEN_TYPES             7

/*
   char * TokenTable[] = {
    "*MESH_NUMVERTEX",
    "*MESH_NUMFACES",
    "*MESH_NUMTVERTEX",
    "*MESH_VERTEX",
    "*MESH_FACE"
   };
 */
// -----------------------------------------------------------------------------
// Utility functions
// -----------------------------------------------------------------------------

char* NextString(char* Str)
{
    int State = STATE_Searching;
    while ( (State != STATE_Ready) && *Str )
    {
        switch ( State )
        {
            case STATE_Searching:

            if ( *Str == '/' )
            {
                State = STATE_Comenting1;
                Str++;
            }
            else if ( (*Str == 0x20) || (*Str == 0x09) || (*Str == 0x0a) || (*Str == 0x0c) )
                Str++;
            else
                State = STATE_Ready;
            break;

            case STATE_Comenting1:

            if ( *Str == '*' ) State = STATE_Comenting2;
            Str++;
            break;

            case STATE_Comenting2:

            if ( *Str == '*' ) State = STATE_Comenting3;
            Str++;
            break;

            case STATE_Comenting3:

            if ( *Str == '/' ) State = STATE_Searching;
            Str++;
            break;
        }
    }

    return(Str);
}
// ----------------------------------------------------------------------------
char* NextWord(char* Str)
{
    // Saltar espacios y tabuladores
    while ( (*Str == ' ') || (*Str == '\t') ) Str++;
    return(Str);
}
// ----------------------------------------------------------------------------
char* WordFinal(char* Str)
{
    // Saltar letras
    while ( (*Str) && (*Str != '\r') && (*Str != '\n') && (*Str != ' ') && (*Str != '\t') ) Str++;
    return(Str);
}
// ----------------------------------------------------------------------------
char* SeparateToken(char* * Token,int* TokenIndex,char* * Args,char* Str)
{
    char* Letra,* TkIndex;

    *Token = NextWord(Str);
    Str = WordFinal(Str);
    *Str = 0;                       // Marcar final de token
    Str++;
    *Args = Str;

    // Buscar siguiente palabra de la cadena
    Str = NextWord(Str);                    // Comienzo de la siguiente palabra

    return(Str);
}
// ----------------------------------------------------------------------------
int E3D_ASELoader_LoadFile(char* Filename,CGMesh* Obj)
{
/*
    FILE *fd;
    char *StrBuff,*Str,*Token,*Args;
    int Lenght,TkIndex;
    int TokenType;

    float    fX,fY,fZ;
    int      iX,iY,iZ;
    uint Index;

    TGeometricObj *AuxObj;

    // ---------------------------------
    // Lectura del contenido del fichero
    // ---------------------------------
    fd = fopen(Filename,"rt");
    if (! fd) return(0);

    fseek(fd,0,SEEK_END);
    Lenght = ftell(fd);

    StrBuff = (char *)malloc(Lenght+1);
    memset((void *)StrBuff,0,Lenght+1);
    if (! StrBuff)
    {
        fclose(fd);
        return(0);
   }

    fseek(fd,0,SEEK_SET);
    fread(StrBuff,Lenght,1,fd);
    fclose(fd);

    // ---------------------------------
    // Parse del contenido del buffer
    // ---------------------------------
    StrBuff[Lenght]= 0;
    Str = StrBuff;
    while (*Str)
    {
        Str = SeparateToken(&Token,&TkIndex,&Args,NextString(Str));

        // Analizar los tokens obtenidos y actuar en consecuencia

        TokenType=0;
        while ((TokenType<NUM_TOKEN_TYPES) && (strcmp(Token,TokenTable[TokenType])))
            TokenType++;

        switch (TokenType)
        {
            case TKTYPE_NUMVERTEX:  Obj->ObjData.NumVert = atoi(Args);
                                    break;

            case TKTYPE_NUMFACES:   Obj->ObjData.NumTris = atoi(Args);
                                    break;

            case TKTYPE_NUMTVERTEX: Obj->ObjData.NumTris = atoi(Args);
                                    //AuxObj = E3D_CreateGeometricObj(Obj->ObjData.NumVert,Obj->ObjData.NumTVert,Obj->ObjData.NumTris,NULL,NULL);
                                    break;

            case TKTYPE_VERTEX:     sscanf(Args,"%i %f %f %f",&Index,&fX,&fY,&fZ);
                                    /*
                                    Obj3D->Vs[Index].v[0] = fX;
                                    Obj3D->Vs[Index].v[1] = fY;
                                    Obj3D->Vs[Index].v[2] = fZ;
 */
/*                                    break;

            case TKTYPE_FACE:       sscanf(Args,"%i: A: %i B: %i C: %i",&Index,&iX,&iY,&iZ);
                                    /*
                                    Obj3D->Tris[Index].V[0] = iX;
                                    Obj3D->Tris[Index].V[1] = iY;
                                    Obj3D->Tris[Index].V[2] = iZ;
 */
    /*break;
       }
       }
     */
    return(1);
}
// ----------------------------------------------------------------------------
