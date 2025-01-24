//-----------------------------------------------------------------------------
#ifndef CGLogChannelH
#define CGLogChannelH
//-----------------------------------------------------------------------------
#include "CGLogger.h"
//-----------------------------------------------------------------------------
class CGLogChannel
{
public:
	
	/// Creates and initializes the log channel object
	CGLogChannel(CGLogger* _poLogger = NULL);
	
	/// Write text to the log channel
	virtual void Write(char *fmt,...);
	
	/// Clear the contents of the log channel
	void Clear()
	{
		m_poLogger->Clear();
	};

	/// Sets a specific logger object for the log channel
	void SetLogger(CGLogger* _poLogger = NULL)
	{
		if (_poLogger == NULL)
			m_poLogger = m_poDefaultLogger;
		else
			m_poLogger = _poLogger;
	};
	
	/// Retrieves the logger object for the log channel
	CGLogger* poGetLogger()
	{
		return(m_poLogger);
	};

protected:

	CGLogger* m_poLogger;
	CGLogger* m_poDefaultLogger;
};
//-----------------------------------------------------------------------------
#endif //-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
