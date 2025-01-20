// ----------------------------------------------------------------------------
#ifndef CGStringH
#define CGStringH
// ----------------------------------------------------------------------------
#include <string.h>
#include <stdlib.h>
#include "MiscTypes.h"
// ----------------------------------------------------------------------------
class CGString
{
	public:
	
		/// Creates an empty string
		CGString() : m_szData(NULL) {};

		/// Frees the resources possibly allocated by the object
		~CGString();

		/// Creates a string with the same contents as the char* string passed as parameter.
		CGString(const char* _szData) : m_szData(NULL) { Assign(_szData); };

		/// Copy constructor: Creates a new string with the same contents as the string supplied as parameter
		CGString(const CGString& _oStr) : m_szData(NULL) { Assign( _oStr.szString() ); };

		/// Creates a string containing the only character passed as parameter
		CGString(char _cChar) : m_szData(NULL)
		{
			char szStr[2] = {_cChar,0};
			Assign(szStr);
		}

		/// Creates a string containing the ascii representation of the integer value
		CGString(int _iValue) : m_szData(NULL)
		{
			char szStr[16];
			_itoa_s(_iValue,szStr,16,10);
			Assign(szStr);
		}
		
		/// Creates a string containing the ascii representation of the uinteger value
		CGString(uint _uiValue) : m_szData(NULL)
		{
			char szStr[16];
			_itoa_s(_uiValue,szStr,16,10);
			Assign(szStr);
		}

		/// Copy the string contents to the current 
		void Assign(const char *_szStr);

		/// Copy the formatted string to the string object
		void Format(char *fmt,...);

		/// Returns the length of the string
		const uint uiLen() const;

		/// Returns the position of a substring inside the string, -1 if not found
		int iPos(const CGString& _oSubStr) const;

		/// Returns the position of a c substring inside the string, -1 if not found
		int iPos(const char* _szStr) const;

		/// Returns the position of a c character inside the string, -1 if not found
		int iPos(char _cChar)
		{
			char szStr[2] = {_cChar,0};
			return ( iPos(szStr) );
		};

		/// Returns the c representation of the string
		const char* szString() const
		{
			return(m_szData);
		};

		/// Returns a Substring of length _uiLen contained within the current string at pos _uiPos
		CGString SubString(uint _uiPos,uint _uiLen) const;

		/// Concatenates the contents of the given string
		void Concat(const CGString& _oStr);

		/// \par: Operators

		/// Compares equality to a given string
		bool operator == (const CGString& _oStr) const;

		/// Compares equality to a given string ignoring case
		bool operator |= (const CGString& _oStr) const;

		/// Compares inequality to a given string
		bool operator != (const CGString& _oStr) const;

		/// Returns the character on the string into the index position
		char operator[](const uint index) const
		{
			if (m_szData == NULL) return(0);
			#ifdef _DEBUG
			uint uiLen = this->uiLen();
			if (index >= uiLen)
				return(0);			
			#endif

			return( m_szData[index] );
		}

		/// Copies the contents of a given string
		CGString operator = (const CGString& _oRight)
		{
			if (this == &_oRight)     // Same object?
				return *this;        // Yes, so skip assignment, and just return *this.
			
			Assign( (char*)_oRight.szString() );			
			return(*this);
		}

		/// Concatenates the contents of the given string
		CGString operator += (const CGString& _oRight)
		{
			Concat(_oRight);
			return(*this);
		};

		/// Concatenates the contents of the given string
		CGString operator + (const CGString& _oStr) const
		{
			CGString asRes(*this);
			asRes.Concat(_oStr);
			return asRes;
		};

		/// Concatenates the given c string
		CGString operator + (const char* _szStr) const
		{
			CGString asRes(*this);
			asRes.Concat( CGString(_szStr) );
			return asRes;
		};

		/// Concatenates the char
		CGString operator + (const char _cChar) const
		{
			CGString asRes(*this);
			asRes.Concat( CGString(_cChar) );
			return asRes;
		};

		/// Returns a copy of the string in upper case
		CGString UpperCase() const;
		
		/// Converts to upper case 
		void ToUpperCase();

		/// Returns a copy of the string in lower case
		CGString LowerCase() const;
		
		/// Converts to lower case 
		void ToLowerCase();

	private:
		
		/// Free the buffer that holds the data
		void Free();
		void Alloc(uint _uiSize);
	
	protected:
		char* m_szData;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
