// Static, Final, This, Super

 class BankAccount{
    public final int interestRate = 11;
    public static String bankName = "SBI"; 
    String accountHolderName;
    double balance;

    BankAccount(String accountHolderName, double balance){
        this.accountHolderName = accountHolderName;
        this.balance = balance;
    }
    void deposit(double amount){
        this.balance += amount;
    }
    void withdraw(double amount){
        this.balance -= amount;
    }
    void displayDetails(){
        System.out.println("Name : " + this.accountHolderName);
        System.out.println("Balance : " + this.balance);
        System.out.println("Bank Name : " + BankAccount.bankName);
        System.out.println("Interest Rate : " + this.interestRate);
    }
 }

 class SavingsAccount extends BankAccount{
    public double minimumBalance = 100;

    public SavingsAccount(String accountHolderName, double balance, double minimumBalance){
        super(accountHolderName, balance);
        this.minimumBalance = minimumBalance;   
    }

    void checkMinimumBalance(){
        if(this.balance < minimumBalance){
            System.out.println("Error Occured!");
        }else{
            System.out.println("Everything alright!");
        }
    }

    void displayDetails(){
        super.displayDetails();
        System.out.println("Minimum Balance : " + this.minimumBalance);
    }
 }


public class StaticFinalThisSuper {
    public static void main(String[] arg){

        SavingsAccount account1 = new SavingsAccount("Shubham Pawade", 100000, 1000);

        System.out.println("Bank Name : " + BankAccount.bankName);
        System.out.println("Interest Rate : " + account1.interestRate);

        account1.deposit(110000);
        account1.withdraw(200000);

        account1.displayDetails();
        account1.checkMinimumBalance();
    }
}
