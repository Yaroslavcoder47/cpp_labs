import java.util.Set;
import java.util.HashSet;

/* SETS OF WORDS */

public class SetUtil
{

    public static String check(String str)
    {
        Set<Character> stack = new HashSet<Character>();
        stack.add('a');
        stack.add('e');
        stack.add('i');
        stack.add('o');
        stack.add('u');
        return processSet(stack, str);
    }

    public static String processSet(Set<Character> set, String str)
    {
        StringBuffer sb = new StringBuffer();

        for (int i = 0; i < str.length(); i++)
        {
            if(!set.contains(str.charAt(i))){
                sb.append(str.charAt(i));
            }
        }

        return sb.toString();
    }
}