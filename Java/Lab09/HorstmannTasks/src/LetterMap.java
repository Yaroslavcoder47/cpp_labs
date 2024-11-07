import java.util.Map;
import java.util.TreeMap;

/*Letter frequency map*/

public class LetterMap
{
    public Map<String, Integer> makeLetterMap(String str)
    {
        Map<String, Integer> map = new TreeMap<>();
        for(int i = 0; i < str.length(); ++i){
            String letter = str.substring(i, i + 1);
            if(map.containsKey(letter)){
                map.put(letter, map.get(letter) + 1);
            } else {
                map.put(letter, 1);
            }
        }
        return map;
    }
}