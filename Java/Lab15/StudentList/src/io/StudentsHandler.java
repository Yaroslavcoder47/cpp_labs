package io;

import collection.Student;
import org.xml.sax.Attributes;
import org.xml.sax.helpers.DefaultHandler;

import java.util.ArrayList;

public class StudentsHandler extends DefaultHandler {
    private Student student;
    private StringBuilder data = null;
    private ArrayList<Student> studentsInfo = new ArrayList<>();

    public ArrayList<Student> getStudentsInfo() {
        return studentsInfo;
    }

    @Override
    public void startElement(String uri, String localName, String qName, Attributes attributes) {
        if (qName.equalsIgnoreCase("student")) {
            student = new Student();
        }
        data = new StringBuilder();
    }

    @Override
    public void endElement(String uri, String localName, String qName) {
        switch (qName.toLowerCase()) {
            case "id":
                student.setId(Integer.parseInt(data.toString()));
                break;
            case "name":
                student.setSurname(data.toString());
                break;
            case "year":
                student.setCourse(Integer.parseInt(data.toString()));
                break;
            case "group":
                student.setGroup(Integer.parseInt(data.toString()));
                break;
            case "student":
                studentsInfo.add(student);
                break;
        }
    }

    @Override
    public void characters(char[] ch, int start, int length) {
        data.append(new String(ch, start, length));
    }
}
