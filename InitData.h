///
///��ʼ�����ݲ�д���ļ�
///

void BatchInsert(LNode* p) {
	printf("==================================��ʼ������=====================================\n");
	JudgeResponseCode(SuperListInsert(p, 1, "001", "JAVA", "����", "�廪������", 520.0));
	JudgeResponseCode(SuperListInsert(p, 2, "002", "VUE.JS", "����", "��ҵ������", 320.0));
	JudgeResponseCode(SuperListInsert(p, 3, "003", "C++", "����", "���������", 700.0));
	JudgeResponseCode(SuperListInsert(p, 4, "004", "Asp.Net", "����", "�ߵȽ���������", 660.0));
	JudgeResponseCode(SuperListInsert(p, 5, "005", "���������", "С��", "A������", 780.0));
	JudgeResponseCode(SuperListInsert(p, 6, "006", "���ݽṹ", "С��", "A������", 680.0));
	JudgeResponseCode(SuperListInsert(p, 7, "007", "���������ϵͳ", "С��", "B������", 220.0));
	JudgeResponseCode(SuperListInsert(p, 8, "008", "���ݽṹ", "С��", "֣�������", 140.0));
	JudgeResponseCode(SuperListInsert(p, 9, "009", "C++�����ŵ�����", "С��", "���Ϲ��̳�����", 380.0));
	JudgeResponseCode(SuperListInsert(p, 10, "010", "C++�����ŵ�����", "С��", "���Ϲ��̳�����", 180.0));
	JudgeResponseCode(SuperListInsert(p, 11, "011", "C++�����ŵ�����", "С��", "���Ϲ��̳�����", 180.0));
	JudgeResponseCode(SuperListInsert(p, 12, "012", "��׿�����ŵ�����", "С��", "A������", 180.0));
	printf("��ǰһ����%d������\n", ListLength(p));
	printf("==================================��ʼ������=====================================\n\n");
}

void InitData() {
	LNode* p;  // pΪָ��LNode��ָ����
	LNode** q = &p; // qָ��ָ���ָ��

	/* ��ʼ��ָ����Ҫ���� ָ��ָ���ָ�룬ͨ��ָ��ָ���ָ�����ı�ָ��ĵ�ַ
	 * ������ͨ������ָ�봫��
	 */

	InitList(q);

	/*
	 * ������������
	 */
	BatchInsert(p);
	if (WriteStructToFile(p) == OK) {
		cout << "д�����ݳɹ�" << endl;
	}
	if (ReadStructFromFile(p) == OK) {
		cout << "��ȡ���ݳɹ�" << endl;
	}
	AccessNodesData(p);
}
