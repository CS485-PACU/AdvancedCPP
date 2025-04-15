class testNames {
public:
	testNames () {};
	virtual ~testNames () {};
};
void foo (testNames x, testNames* pData, int v, testNames y) {
	return;
}
void foo (testNames x) {
	return;
}