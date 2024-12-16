package strategy;

import collection.Student;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import java.util.ArrayList;

public interface ReadStrategy {
    ArrayList<Student> readData(String filepath) throws ParserConfigurationException, SAXException, IOException;
}
