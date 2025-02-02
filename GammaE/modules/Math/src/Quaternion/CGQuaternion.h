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
#ifndef CGQuaternionH
#define CGQuaternionH
// ----------------------------------------------------------------------------
#include "..\Matrix\CGMatrix4x4.h"
#include "..\Vector\CGVect4.h"
#include "..\Vector\CGVect3.h"
// ----------------------------------------------------------------------------
class CGQuaternion
{
    public:
        void Slerp(CGQuaternion& _Src, CGQuaternion& _Dst, float _fFactor);

        CGMatrix4x4 & ToMatrix();

        void FromMatrix(CGMatrix4x4 &_Matrix);
        void FromVector(CGVect4& _Vect);
        void FromComponents(CGVect3& _Vect,float _fRotation);

    private:
        float quat[4];
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
