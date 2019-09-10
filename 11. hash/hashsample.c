typedef unsigned int Index;
Index Hash(const char *Key, int TableSize)
{
	unsigned int HashVal = 0;
	while(*Key != '\0')
		HashVal += *Key++;
	
	return HashVal % TableSize;
}