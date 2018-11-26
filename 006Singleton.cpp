#include<iostream>
#include<string>
using namespace std;

class CA
{
	CA()
	{
		cout << "CA Ctor" << endl;
	}
	~CA()
	{
		cout << "CA D-tor" << endl;
	}
	static CA *head;
public:
	void funCA()
	{
		cout << "Fun CA" << endl;
	}
	static CA* CreateCA()
	{
		if (head == NULL)
		{
			head = new CA();
			/*
				push	1
				call	??2@YAPAXI@Z				; operator new
				add	esp, 4
	mov	DWORD PTR $T2[ebp], eax
	mov	DWORD PTR __$EHRec$[ebp+8], 0
	cmp	DWORD PTR $T2[ebp], 0
	je	SHORT $LN4@CreateCA
	mov	ecx, DWORD PTR $T2[ebp]
					call	??0CA@@AAE@XZ				; CA::CA
	mov	DWORD PTR tv76[ebp], eax
	jmp	SHORT $LN5@CreateCA
$LN4@CreateCA:
	mov	DWORD PTR tv76[ebp], 0
$LN5@CreateCA:
	mov	eax, DWORD PTR tv76[ebp]
	mov	DWORD PTR $T3[ebp], eax
	mov	DWORD PTR __$EHRec$[ebp+8], -1
	mov	ecx, DWORD PTR $T3[ebp]
	mov	DWORD PTR ?head@CA@@0PAV1@A, ecx	; CA::head
$LN2@CreateCA:
			*/
		}
		return head;
	}
	friend class Smart;
};
CA *CA::head;


class Smart
{
	CA *ptr;
	static int count;
	static void* operator new(size_t size)
	{

	}
	static void operator delete(void*p)
	{

	}
public:
	Smart():ptr(CA::CreateCA())
	{
		count++;
	}
	CA* operator->()
	{
		return ptr;
	}
	~Smart()
	{
		count--;
		if (count == 0)
		{
			delete ptr;
			CA::head = NULL;
		}
	}
};
int Smart::count = 0;
void main1()
{
	Smart sm;
	Smart sm1;
	Smart sm2;
	Smart sm3;

	sm->funCA();
}

void main()
{
	CA *ptr = CA::CreateCA();
	ptr->funCA();
	
	
}