//-----------------------------------------------------------------------------
#ifndef CSmoother_h
#define CSmoother_h 1
//-----------------------------------------------------------------------------
class CSmoother 
{
	public:
		CSmoother(float _fSmoothFact = 1.0f) : m_fAccum(0.0f) { Init(_fSmoothFact); };
		
		/// Inializes the smoother object using the initial smooth factor
		void Init(float _fSmoothFact);
		
		/// Retrieves the a smooth value given the raw input value
		float fValue(float _fInputVal);

	protected:
		float m_fSmoothFact;

		float m_fAccum;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
