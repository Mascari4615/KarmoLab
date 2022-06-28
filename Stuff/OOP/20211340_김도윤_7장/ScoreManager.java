import java.util.*;

public class ScoreManager 
{
    private ArrayList<Student> database = new ArrayList<Student>();
    private Scanner s = new Scanner(System.in);

    private class Student 
    {
        private String id = "";
        private String name = "";
        private int attendancePoint = 0;
        private int practicePoint = 0;
        private int midtermExamPoint = 0;
        private int finalExamPoint = 0;
        private int totalScore = 0;
        private char gpa = ' ';

        public String GetID() { return id; }
        public String GetName() { return name; }
        public int GetAttendancePoint() { return attendancePoint; }
        public int GetPracticePoint() { return practicePoint; }
        public int GetMidtermExamPoint() { return midtermExamPoint; }
        public int GetFinalExamPoint() { return finalExamPoint; }
        public int GetTotalScore() { return totalScore; }
        public char GetGPA() { return gpa; }

        public void SetID(String id) { this.id = id; }
        public void SetName(String name) { this.name = name; }
        public void SetAttendancePoint(int attendancePoint) { this.attendancePoint = attendancePoint; }
        public void SetPracticePoint(int practicePoint) { this.practicePoint = practicePoint; }
        public void SetMidtermExamPoint(int midtermExamPoint) { this.midtermExamPoint = midtermExamPoint; }
        public void SetFinalExamPoint(int finalExamPoint) { this.finalExamPoint = finalExamPoint; }
        public void SetTotalScore(int totalScore) { this.totalScore = totalScore; }
        public void SetGPA(char gpa) { this.gpa = gpa; }
    }

    public void Execute() 
    {
        System.out.println("** 성적처리 프로그램입니다. **");

        while (true) 
        {
            int command = s.nextInt();
            switch (command) 
            {
                // 학생 성적 정보 입력
                case 1:
                    System.out.println("학생 성적 정보 입력\n>>");
                    AppendStudentData();
                    break;
                // 학생 성적 조회
                case 2:
                    System.out.println("성적을 조회할 학생의 ID 입력\n>>");
                    PrintStudentData(s.next());                    
                    break;
                // 학생 성적 삭제
                case 3:
                    System.out.println("성적을 삭제할 학생의 ID 입력\n>>");
                    DeleteStudentData(s.next());                    
                    break;
                // 종료
                case 4:
                    System.out.print("프로그램을 종료합니다...");
                    s.close();
                    return;
                default:
                    break;
            }
        }
    }

    private int CalcTotalScore(int attendancePoint, int practicePoint, int midtermExamPoint, int finalExamPoint)
    {
        int totalScore = 0;
        totalScore += (int)((double)attendancePoint * .1);
        totalScore += (int)((double)practicePoint * .3);
        totalScore += (int)((double)attendancePoint * .3);
        totalScore += (int)((double)midtermExamPoint * .3);
        return totalScore;
    }

    private char CalcGPA(int totalScore)
    {
        if (90 <= totalScore && totalScore <= 100) return 'A';
        if (80 <= totalScore && totalScore <= 89) return 'B';
        if (70 <= totalScore && totalScore <= 79) return 'C';
        if (60 <= totalScore && totalScore <= 69) return 'D';
        if (0 <= totalScore && totalScore <= 59) return 'F';
        return ' ';
    }

    private void AppendStudentData() 
    {
        Student student = new Student();
        System.out.println("학번:");
        student.SetID(s.next());
        System.out.println("이름:");
        student.SetName(s.next());
        System.out.println("출석점수:");
        student.SetAttendancePoint(s.nextInt());
        System.out.println("실습과제");
        student.SetPracticePoint(s.nextInt());
        System.out.println("중간고사:");
        student.SetMidtermExamPoint(s.nextInt());
        System.out.println("기말고사:");
        student.SetFinalExamPoint(s.nextInt());
        student.SetTotalScore(CalcTotalScore(student.GetAttendancePoint(), student.GetPracticePoint(), 
                                            student.GetMidtermExamPoint(), student.GetFinalExamPoint()));
        System.out.println("총점:"+student.GetTotalScore());
        student.SetGPA(CalcGPA(student.GetTotalScore()));
        System.out.println("학점:"+student.GetGPA());
        database.add(student);
    }

    private void PrintStudentData(String id)
    {
        Student s = null;
        for (int i = 0; i < database.size(); i++) 
        {
            s = database.get(0);
            if (database.get(i).GetID() == id) break;
        }
        System.out.println("학번:" + s.GetID());
        System.out.println("이름:" + s.GetName());
        System.out.println("출석점수:" + s.GetAttendancePoint());
        System.out.println("실습과제" + s.GetPracticePoint());
        System.out.println("중간고사:" + s.GetMidtermExamPoint());
        System.out.println("기말고사:" + s.GetFinalExamPoint());
        System.out.println("총점:" + s.GetTotalScore());
        System.out.println("학점:" + s.GetGPA());
    }
    
    private void DeleteStudentData(String id)
    {
        for (int i = 0; i < database.size(); i++) 
        {
            if (database.get(i).GetID() == id)
            {
                database.remove(i);
                break;
            }
        }
    }

    public int GetAverageScore()
    {
        int totalScore = 0;
        for (int i = 0; i < database.size(); i++) 
        {
            totalScore += database.get(i).GetTotalScore();
        }
        return totalScore / database.size();
    }

    public int GetHighestScore()
    {
        int highestScore = 0;
        for (int i = 0; i < database.size(); i++) 
        {
            if (highestScore < database.get(i).GetTotalScore())
            {
                highestScore = database.get(i).GetTotalScore();
            }
        }
        return highestScore;
    }

    public int GetLowestScore()
    {
        int lowestScore = 0;
        for (int i = 0; i < database.size(); i++) 
        {
            if (lowestScore > database.get(i).GetTotalScore())
            {
                lowestScore = database.get(i).GetTotalScore();
            }
        }
        return lowestScore;
    }
}