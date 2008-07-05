
#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
// CHashEntry()
// Base class, to be derived from.
////////////////////////////////////////////////////////////////////////////////////////////////////
class CHashEntry
{
////////////////////////////////////////////////////////////////////////////////////////////////////
protected:
	DWORD			m_dwHashValue;
	CHashEntry *	m_pNextHashEntry;				// Next hash entry in list.

////////////////////////////////////////////////////////////////////////////////////////////////////
public:
	CHashEntry( DWORD dwHashValue, void * pObject )
	{
		m_dwHashValue = dwHashValue;
		m_pNextHashEntry = NULL;
	}

	virtual ~CHashEntry(void)
	{
	}

	inline DWORD GetHashValue()					{	return m_dwHashValue;		}
	inline void SetHashValue( DWORD dwHash )	{	m_dwHashValue = dwHash;		}
	inline CHashEntry * GetNext()				{	return m_pNextHashEntry;	}
	inline void SetNext( CHashEntry * pNext )	{	m_pNextHashEntry = pNext;	}
};



////////////////////////////////////////////////////////////////////////////////////////////////////
class CHashTable
{
////////////////////////////////////////////////////////////////////////////////////////////////////
public:
	static const int s_iDefaultTableSize = 503;		// Prime number.

////////////////////////////////////////////////////////////////////////////////////////////////////
private:
	DWORD m_dwTableSize;
	DWORD m_dwTotalEntriesAdded;
	CHashEntry ** m_ppHashTable;
	bool m_bValidateEntries;			// If true, check all entries for a hash value clash.

////////////////////////////////////////////////////////////////////////////////////////////////////
public:
	////////////////////////////////////////////////////////////////////////////////////////////
	CHashTable( DWORD dwTableSize = (DWORD) s_iDefaultTableSize, bool bValidateEntries = false );
	~CHashTable(void);

	////////////////////////////////////////////////////////////////////////////////////////////
	// Add the hash entry to the hash table. If a match is already found, a pointer is returned
	// to it, otherwise NULL.
	CHashEntry * AddHashEntry( CHashEntry * pHashEntry );

	////////////////////////////////////////////////////////////////////////////////////////////
	// Returns a hash entry with a matching hash value, NULL if no match is found.
	CHashEntry * GetHashEntry( DWORD dwHashSearchValue );

	////////////////////////////////////////////////////////////////////////////////////////////
	CHashEntry * GetLeadHashEntryByIndex( DWORD dwIndex );

	////////////////////////////////////////////////////////////////////////////////////////////
	DWORD GetTableSize() {	return m_dwTableSize;	}

	////////////////////////////////////////////////////////////////////////////////////////////
	DWORD GetNumChildren( CHashEntry * pEntry );

	////////////////////////////////////////////////////////////////////////////////////////////
	static DWORD GenerateHashValue( const char * szString );
};