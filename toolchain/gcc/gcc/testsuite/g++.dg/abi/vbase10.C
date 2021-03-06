// { dg-do compile }
// { dg-options "-Wabi -fabi-version=1" }
// On ARM processors, the alignment of B will be 4 even though it
// contains only a single "char".  That would avoids the situation
// that the warning below is designed to catch.  We therefore
// explicitly set the default structure alignment to 1.
// { dg-options "-Wabi -fabi-version=1 -mstructure-size-boundary=8" { target arm*-*-* } }

struct A { virtual void f(); char c1; };
struct B { B(); char c2; };
struct C : public A, public virtual B {}; // { dg-warning "ABI" }

