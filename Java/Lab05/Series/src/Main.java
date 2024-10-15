public class Main{
    public static void main(String[] args){
        try{
            GUI interFace = new GUI();
        }
        catch (NumberFormatException exc){
            System.err.println("Error: " + exc.getMessage());
        }
    }
}

