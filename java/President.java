import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;
import java.util.jar.Attributes.Name;

class MyCustomException extends Exception {
    MyCustomException(String message) {
        super(message);
    }
}

/**
 * President
 */
public class President {

    private String Name;
    private Date TenureStartDate;
    private Date TenureEndDate;
    private String BirthPlace;
    private String Profession;

    President(String Name, Date TenureStartDate, Date TenureEndDate, String BirthPlace, String Profession) {
        this.Name = Name;
        this.TenureStartDate = TenureStartDate;
        this.TenureEndDate = TenureEndDate;
        this.BirthPlace = BirthPlace;
        this.Profession = Profession;
    }

    void myCustomException() throws MyCustomException {
        if (Name == null) {
            throw new MyCustomException("Name is null");
        }
        if (TenureStartDate.after(TenureEndDate)) {
            throw new MyCustomException("TenureStartDate is after TenureEndDate");
        }
    }

    public String getName() {
        return Name;
    }

    public void setName(String Name) {
        this.Name = Name;
    }

    public Date getTenureStartDate() {
        return TenureStartDate;
    }

    public void setTenureStartDate(Date TenureStartDate) {
        this.TenureStartDate = TenureStartDate;
    }

    public Date getTenureEndDate() {
        return TenureEndDate;
    }

    public void setTenureEndDate(Date TenureEndDate) {
        this.TenureEndDate = TenureEndDate;
    }

    public String getBirthPlace() {
        return BirthPlace;
    }

    public void setBirthPlace(String BirthPlace) {
        this.BirthPlace = BirthPlace;
    }

    public String getProfession() {
        return Profession;
    }

    public void setProfession(String Profession) {
        this.Profession = Profession;
    }

    @Override
    public String toString() {
        return Name + " was India\'s president during" + TenureStartDate + " to " + TenureEndDate + ".";
    }


    public static void main(String[] args) {
        List<President> presidents = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        int choice = -1;
        while (choice != 3) {
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Enter the name of the president");
                    String name = scanner.next();
                    System.out.println("Enter the tenure start date of the president");
                    Date tenureStartDate = new Date(scanner.nextLong());
                    System.out.println("Enter the tenure end date of the president");
                    Date tenureEndDate = new Date(scanner.nextLong());
                    System.out.println("Enter the birth place of the president");
                    String birthPlace = scanner.next();
                    System.out.println("Enter the profession of the president");
                    String profession = scanner.next();
                    President president = new President(name, tenureStartDate, tenureEndDate, birthPlace, profession);
                    try {
                        president.myCustomException();
                    } catch (MyCustomException e) {
                        System.out.println(e.getMessage());
                    }
                    presidents.add(president);
                    break;
                case 2:
                    for (President president1 : presidents) {
                        System.out.println(president1.toString());
                    }
                    break;
                case 3:
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        }
        scanner.close();
    }
}
