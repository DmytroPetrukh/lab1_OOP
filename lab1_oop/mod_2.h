typedef bool (*CompareFunc)(const char*, const char*);

void copyString(char* dest, const char* src);

void bubbleSort(char words[][100], int count, CompareFunc comp);

bool compareSumOfCodes(const char* a, const char* b);

void calcMeans(char words[][100], int count, double& arithMean, double& harmMean);
