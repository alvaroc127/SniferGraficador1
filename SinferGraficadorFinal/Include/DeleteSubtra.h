#if !defined (_DELETESUBTRA_)
#define _DELETESUBTRA_
#pragma once
template<class T> class DeleteSubtra
{

public:	

	/// <summary>
	/// Operator()s the specified x.
	/// </summary>
	/// <param name="x">The x.</param>
	/// <returns></returns>
	bool operator()(T x) const 
	{
		delete x;
		return  true;
	}

};

#endif // !