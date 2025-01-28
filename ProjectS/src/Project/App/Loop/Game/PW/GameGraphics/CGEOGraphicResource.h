// -----------------------------------------------------------------------------
#ifndef CGEOGraphicResourceH
#define CGEOGraphicResourceH
// -----------------------------------------------------------------------------
class CTex;
class MTH_CPoint3;
class GEOM_CompositeGeometry;
// -----------------------------------------------------------------------------
class CGraphicResource
{
public: CGraphicResource(char* _szResource);

		void Mins(MTH_CPoint3& _oMins) {m_oMins = _oMins;};
		void Maxs(MTH_CPoint3& _oMaxs) {m_oMaxs = _oMaxs;};
		
		MTH_CPoint3 oMins() { return(m_oMins); };
		MTH_CPoint3 oMaxs() { return(m_oMaxs); };
		
		MTH_CPoint3 oGetCP(char* _szCPName);

public:
		GEOM_CompositeGeometry*	m_poGeo;

private:
		MTH_CPoint3 m_oMins;
		MTH_CPoint3 m_oMaxs;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------