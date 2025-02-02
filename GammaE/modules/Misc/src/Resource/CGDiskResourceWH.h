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
#ifndef CGDiskResourceWHH
#define CGDiskResourceWHH
// ----------------------------------------------------------------------------
#include "CGResourceWH.h"
// ----------------------------------------------------------------------------
template <typename T,typename B>
class CGDiskResourceWH : public CGResourceWH <T,B>
{
/*
   private:
    CGDiskResourceWH(){};
    ~CGDiskResourceWH(){};
 */
    public:

        // / This function can be overloaded in derivate classes
        virtual void Reload()
        {
            ReloadINT();
        }

        // / Helper function to allow the reload of the resources at parent level i.e. the method of this class
        void ParentReload()
        {
            ReloadINT();
        }

        // / Loads the resource identified by the given filename and returns the identifier index into the warehouse
        int iLoad(const CGString& _sFilename)
        {
            // Search for the file
            T* poObj = m_oWH.oGetVar(_sFilename);
            if ( poObj == NULL )
            {
                T* poRes = poLoadResource(_sFilename);
                return( this->uiAdd(poRes,_sFilename) );        // http://www.parashift.com/c++-faq-lite/templates.html#faq-35.19
            }
            else
            {
                return ( m_oWH.iGetElemIdx( poObj ) );
            }
        }

        // / Loads the resource identified by the given filename and returns the object
        T* poLoad(const CGString& _sFilename)
        {
            int iIdx = iLoad(_sFilename);
            if ( iIdx == -1 ) return(NULL);

            return ( poGet( (uint)iIdx ) );
        }

        // / Function to override for every type of Disk Resource
        virtual T* poLoadResource(const CGString& _sFilename) = 0;

    private:
        // Internal reload resource code
        void ReloadINT()
        {
            for ( uint i = 0; i < m_oWH.uiNumElems(); i++ )
            {
                const CGString& sFilename = m_oWH.sGetElemName(i);
                T* poNewRes = poLoadResource(sFilename);

                if ( poNewRes != NULL )
                {
                    T* poRes = m_oWH.oGetElem(i);

                    // Swap elems: We have to copy new resource data into old one to prevent objects having invalid references by just
                    // substituting the contents of the element in the resource array.

                    T oAux = *poRes;
                    *poRes = *poNewRes;
                    *poNewRes = oAux;

                    // Invalidate just in case some one needs to know the information inside this object has changed.
                    poRes->Invalidate();    // Object should be derived from CGResource

                    // delete old object ???
                    // mDel poNewRes;
                    // Old object deletion should be performed automatically because it's allocated on the stack
                }
            }
        }
};
// ----------------------------------------------------------------------------
#endif // CGDiskResourceWHH
// ----------------------------------------------------------------------------
