package io;

import collection.Student;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class StudentsDOMParser {
    private ArrayList<Student> students = new ArrayList<>();
    private Student student;

    public ArrayList<Student> parseStudents(String filePath) throws ParserConfigurationException, IOException, SAXException {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = factory.newDocumentBuilder();
        Document document = builder.parse(new File(filePath));
        document.getDocumentElement().normalize();

        NodeList studentNodes = document.getElementsByTagName("student");

        for (int i = 0; i < studentNodes.getLength(); i++) {
            Node node = studentNodes.item(i);

            if (node.getNodeType() == Node.ELEMENT_NODE) {
                Element studentElement = (Element) node;

                int id = Integer.parseInt(studentElement.getElementsByTagName("id").item(0).getTextContent());
                String name = studentElement.getElementsByTagName("name").item(0).getTextContent();
                int course = Integer.parseInt(studentElement.getElementsByTagName("year").item(0).getTextContent());
                int group = Integer.parseInt(studentElement.getElementsByTagName("group").item(0).getTextContent());

                student = new Student(id, name, course, group);
                students.add(student);
            }
        }

        return students;
    }
}
