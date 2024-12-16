package strategy;

import collection.Student;
import io.StudentsDOMParser;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import java.util.ArrayList;

public class ReadWithDOM implements ReadStrategy {
    @Override
    public ArrayList<Student> readData(String filepath) throws ParserConfigurationException, IOException, SAXException {
        System.out.println("Reading data with DOM");
        StudentsDOMParser parser = new StudentsDOMParser();
        return parser.parseStudents(filepath);
    }
}
