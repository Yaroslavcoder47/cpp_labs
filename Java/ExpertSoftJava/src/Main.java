import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        merge(new ArrayList<>(List.of(1, 3, 5)), new ArrayList<>(List.of(2, 6, 8)));
    }

    public static void merge(ArrayList<Integer> a, ArrayList<Integer> b){
        int initialSize = a.size();

        for(int i = 0; i < b.size(); ++i){
            a.add(null);
        }

        int i = initialSize - 1;
        int j = b.size() - 1;
        int k = a.size() - 1;

        while(i >= 0 && j >= 0){
            if(a.get(i) > b.get(j)){
                a.set(k, a.get(i));
                --i;
            }else{
                a.set(k, b.get(j));
                --j;
            }
            --k;
        }

        while(j >= 0){
            a.set(k, b.get(j));
            --j;
            --k;
        }
    }
}