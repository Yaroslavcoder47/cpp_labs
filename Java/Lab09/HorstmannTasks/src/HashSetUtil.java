import java.util.Map;
import java.util.HashSet;

/* HASH SETS OF PEOPLE */
public class HashSetUtil
{

    public static boolean check(String s1, String s2)
    {
        Person p1 = new Person(s1,s2);
        Person p2 = new Person(s1,s2);

        HashSet<Person> people = new HashSet<Person>();
        people.add(p1);

        return processSet(people, p2);
    }


    public static boolean processSet(HashSet<Person> people, Person person)
    {
        return people.contains(person);
    }


    /* Inner class Person simply has two name fields fn, first name and ln, last name,
       a constructor and the toString  method override
    */
    static class Person
    {
        private String fn;
        private String ln;

        public Person(String fn, String ln) {
            this.fn = fn;
            this.ln = ln;
        }

        public String toString()
        {
            return ln + ", " + fn;
        }

        // TODO: wite a hashcode override method
        public int hashCode()
        {
            return 31 * fn.hashCode() + ln.hashCode();
        }

        // TODO: wite an equals override method
        public boolean equals(Object object)
        {
            return object instanceof Person && fn.equals(((Person)object).fn) && ln.equals(((Person)object).ln);
        }
    }

}