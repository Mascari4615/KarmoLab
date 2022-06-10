import java.util.*;

public class CustomerManager 
{
    private HashMap<String, Customer> database = new HashMap<String, Customer>();

    private class Customer 
    {
        private String name = "";
        private String phoneNumber = "";
        private int point = 0;

        public Customer(String name, String phoneNumber, int point) 
        {
            this.name = name;
            this.phoneNumber = phoneNumber;          
            this.point = point;
        }

        public String GetPhoneName() { return name; }
        public String GetPhoneNumber() { return phoneNumber; }
        public int GetPoint() { return point; }
    }

    public void Execute() 
    {
        System.out.println("** 포인트 관리 프로그램입니다. **");
        Scanner s = new Scanner(System.in);

        while (true) 
        {
            int command = s.nextInt();
            switch (command) 
            {
                // 고객 정보 입력
                case 1:
                    System.out.println("고객 정보 (이름, 전화번호, 포인트) 입력\n>>");
                    AppendCustomerData(s.next(), s.next(), s.nextInt());
                    PrintAllCustomersData();
                    break;
                // 고객 정보 조회
                case 2:
                    System.out.println("정보를 조회할 고객의 전화번호 입력\n>>");
                    PrintCustomerData(s.next());                    
                    break;
                // 종료
                case 3:
                    System.out.print("프로그램을 종료합니다...");
                    s.close();
                    return;
                default:
                    break;
            }
        }
    }

    private void AppendCustomerData(String name, String phoneNumber, int point)
    {
        database.put(phoneNumber, new Customer(name, phoneNumber, point));
    }

    private void PrintCustomerData(String phoneNumber)
    {
        Customer c = database.get(phoneNumber);
        System.out.println(c.GetPhoneName() + ", " + c.GetPhoneNumber() + ", " + c.GetPoint());
    }

    private void PrintAllCustomersData()
    {
        // 해쉬 맵의 키들을 Set으로 가져오고, Set을 Iterator로 만들어 각 Key를 매개변수로 PrintCustomerData 함수 호출
        // 해쉬 맵의 키는 각 고객의 전화번호
        Iterator<String> keyset = database.keySet().iterator();
        while (keyset.hasNext()) 
        {
            PrintCustomerData(keyset.next());
        }
    }
}