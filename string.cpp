void reverseString(string s) {
	const char * header= s.c_str();
	const size_t length = strlen(header);//求字符长度
	char *temp = new char[length+1];//新建一个等长度的字符数组,+1是因为\0参数
	strcpy_s(temp,length+1, header);//字符串拷贝
	for (size_t i = 0; i <= length / 2; ++i)//对字符数组中的字符反转,循环执行条件为标识小于或等于字符长度一半
	{
		char c = temp[i];
		temp[i] = temp[length - i - 1];
		temp[length - i - 1] = c;
	}
	cout << temp<< endl;
}