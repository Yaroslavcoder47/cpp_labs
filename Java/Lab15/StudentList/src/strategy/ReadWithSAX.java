package strategy;

import collection.Student;
import io.StudentsHandler;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class ReadWithSAX implements ReadStrategy {
    @Override
    public ArrayList<Student> readData(String filepath) throws ParserConfigurationException, SAXException, IOException {
        System.out.println("Reading data with SAX");
        File file = new File(filepath);
        SAXParserFactory factory = SAXParserFactory.newInstance();
        SAXParser saxParser = factory.newSAXParser();
        StudentsHandler handler = new StudentsHandler();
        saxParser.parse(file, handler);
        return handler.getStudentsInfo();
    }
}
