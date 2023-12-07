///**
// * Description: 
// */
//
//class Base {
//private:
//	int x;
//protected:
//	int y;
//public:
//	int z;
//};
//
//class Derived1 : private Base {
//	
//};
//
//class Derived2 : protected Base {
//	// x is not accessible.
//	// y is protected.
//	// z is public.
//};
//
//class Derived3 : public Base {
//	// x is not accessible.
//	// y is protected.
//	// z is public.
//};
//
//int main()
//{
//
//}

class MyClass {
	private:
		privateVar;
	protected:
		protectedVar;
	public:
		publicVar;
}

class DerivedPublic : public MyClass {
	// publicVar is public
	// protectedVar is protected
	// privateVar is not accessible
};

class DerivedProtected : protected MyClass {
	// publicVar is protected
	// protectedVar is protected
	// privateVar is not accessible
};

class DerivedPrivate : private MyClass {
	// publicVar is private
	// protectedVar is private
	// privateVar is not accessible
};

class DerivedPrivate : virtual MyClass {
	// publicVar is private
	// protectedVar is private
	// privateVar is not accessible
};
