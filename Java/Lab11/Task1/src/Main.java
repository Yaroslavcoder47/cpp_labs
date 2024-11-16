import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        ArrayList<String> arr1 = new ArrayList<>(List.of(new String[]{"Apple", "Banana", "Orange", "Grapes", "Pineapple", "Mango", "Peach", "Cherry", "Watermelon", "Strawberry",
                "Blueberry", "Raspberry", "Lemon", "Lime", "Papaya", "Apricot", "Coconut", "Plum", "Pear", "Kiwi"
        }));
        ArrayList<String> arr2 = new ArrayList<>(List.of(new String[]{"Carrot", "Cucumber", "Tomato", "Potato", "Lettuce", "Spinach", "Broccoli", "Cauliflower", "Peas", "Onion",
                "Garlic", "Bell Pepper", "Zucchini", "Radish", "Eggplant", "Squash", "Cabbage", "Asparagus", "Artichoke", "Celery"
        }));
        MyFrame frame = new MyFrame(arr1, arr2);
    }
}