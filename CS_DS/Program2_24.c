
struct Address
{
	char name[10];
	char phoneNumber[13];
	char address[10];
	char birthDay[10];
	//목록 추가 탐색 삭제
};

void PrintAddresses()


void Program2_24()
{
	struct Address addresses[4] =
	{
		{"가나다", "010-0000-0000", "서울", "1월 1일"},
		{"라마바", "010-1111-1111", "인천", "2월 1일"},
		{"사아자", "010-2222-2222", "송도", "3월 1일"},
		{"차카타", "010-3333-3333", "부산", "4월 1일"},
	};

	while (1)
	{
		int command = 4;

		printf("명령을 입력하세요 : ");
		scanf("%d", &command);

		switch (command)
		{
			case 0: // 목록
				printf("이름\t\t번호\t\t주소\t\t생일\n");
				for (int i = 0; i < sizeof(addresses) / sizeof(struct Address); i++)
				{
					printf("%s\t\t%s\t\t%s\t\t%s\n", addresses[i].name, addresses[i].phoneNumber, addresses[i].address, addresses[i].birthDay);
				}
				break;
			case 1: // 추가
				exit(0);
				break;
			case 2: // 탐색
				exit(0);
				break;
			case 3: // 삭제
				printf("색인을 입력하세요 : ");
				scanf("%d", &command);
				break;
			case 4: // 종료
				exit(0);
				break;
			default:
				break;
		}
	}

}

void main()
{
	return 0;
}