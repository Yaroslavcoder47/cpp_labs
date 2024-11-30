public class KeyPressSubject extends DefaultSubject{
    private String keyName;

    public String getKeyName(){
        return keyName;
    }

    public void keyPressed(String keyName){
        this.keyName = keyName;
        notifyObservers();
    }
}
