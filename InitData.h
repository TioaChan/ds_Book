///
///初始化数据并写入文件
///

void BatchInsert(LNode* p) {
	printf("==================================初始化数据=====================================\n");
	JudgeResponseCode(SuperListInsert(p, 1, "001", "JAVA", "张三", "清华出版社", 520.0));
	JudgeResponseCode(SuperListInsert(p, 2, "002", "VUE.JS", "李四", "工业出版社", 320.0));
	JudgeResponseCode(SuperListInsert(p, 3, "003", "C++", "王五", "北大出版社", 700.0));
	JudgeResponseCode(SuperListInsert(p, 4, "004", "Asp.Net", "赵六", "高等教育出版社", 660.0));
	JudgeResponseCode(SuperListInsert(p, 5, "005", "计算机网络", "小明", "A出版社", 780.0));
	JudgeResponseCode(SuperListInsert(p, 6, "006", "数据结构", "小明", "A出版社", 680.0));
	JudgeResponseCode(SuperListInsert(p, 7, "007", "计算机操作系统", "小红", "B出版社", 220.0));
	JudgeResponseCode(SuperListInsert(p, 8, "008", "数据结构", "小蓝", "郑大出版社", 140.0));
	JudgeResponseCode(SuperListInsert(p, 9, "009", "C++从入门到放弃", "小智", "河南工程出版社", 380.0));
	JudgeResponseCode(SuperListInsert(p, 10, "010", "C++从入门到放弃", "小芳", "河南工程出版社", 180.0));
	JudgeResponseCode(SuperListInsert(p, 11, "011", "C++从入门到放弃", "小梨", "河南工程出版社", 180.0));
	JudgeResponseCode(SuperListInsert(p, 12, "012", "安卓从入门到放弃", "小明", "A出版社", 180.0));
	printf("当前一共有%d个数据\n", ListLength(p));
	printf("==================================初始化数据=====================================\n\n");
}

void InitData() {
	LNode* p;  // p为指向LNode的指针体
	LNode** q = &p; // q指向指针的指针

	/* 初始化指针需要给入 指向指针的指针，通过指向指针的指针来改变指针的地址
	 * 这里是通过二级指针传递
	 */

	InitList(q);

	/*
	 * 批量插入数据
	 */
	BatchInsert(p);
	if (WriteStructToFile(p) == OK) {
		cout << "写入数据成功" << endl;
	}
	if (ReadStructFromFile(p) == OK) {
		cout << "读取数据成功" << endl;
	}
	AccessNodesData(p);
}
