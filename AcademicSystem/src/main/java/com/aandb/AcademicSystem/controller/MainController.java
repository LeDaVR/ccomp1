package com.aandb.AcademicSystem.controller;

import java.sql.SQLException;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

import com.aandb.AcademicSystem.Application;
import com.aandb.AcademicSystem.model.Student;
import com.aandb.AcademicSystem.model.Silabus;
import com.aandb.AcademicSystem.model.Cronograma;
import com.aandb.AcademicSystem.model.Competencias;
import com.aandb.AcademicSystem.model.Resultados;
import com.aandb.AcademicSystem.model.Subject;

@Controller
public class MainController
{
	private int foreignkey;
	
	public void setforeignkey(int _key) {
		foreignkey=_key;
	}
	
    @RequestMapping("/greeting")
    public String greeting(@RequestParam(name = "name", required = false, defaultValue = "Guy") String name, Model model)
    {
        model.addAttribute("name", name);
        return "greeting";
    }
    
    @RequestMapping("/students")
    public String students(Model model) throws SQLException
    {
        model.addAttribute("students", Application.studentDAO.listStudents());
        return "students";
    }
    
    @RequestMapping("/subjects")
    public String subjects(Model model) throws SQLException
    {
        model.addAttribute("subjects", Application.subjectDAO.listSubjects());
        return "subjects";
    }
    
    @RequestMapping(method = {RequestMethod.POST, RequestMethod.GET}, value = "/registerStudent")
    public String registerStudent(@RequestParam(name = "cui") String cui,
    							  @RequestParam(name = "name") String name,
    							  @RequestParam(name = "lastName") String lastName,
    							  @RequestParam(name = "age") String age,
    							  @RequestParam(name = "sex") String sex) throws SQLException
    {
    	Student student = new Student(Integer.parseInt(cui), name, lastName, Integer.parseInt(age), sex);
    	Application.studentDAO.insert(student);
        return "redirect:index.html";
    }
    
    @RequestMapping(method = {RequestMethod.POST, RequestMethod.GET}, value = "/subjectInformation")
    public String subjectInformation(Model model) throws SQLException
    {
    	model.addAttribute("subjects", Application.subjectDAO.listSubjects());
        return "selectSubject";
    }
    
    @RequestMapping(method = {RequestMethod.POST, RequestMethod.GET}, value="/selectSubject")
    public String selectSubject(@RequestParam(name = "selected") String selected) throws SQLException
    {
    	Subject curso = new Subject();
    	curso=Application.subjectDAO.getSubjectbyName(selected);
    	foreignkey=curso.getCasi();
    	return "registerSilabus";
    }
    
    @RequestMapping(method = {RequestMethod.POST, RequestMethod.GET}, value = "/registerSilabus")
    public String registerSilabo(/*@RequestParam(name = "semestre") String semestre,
								 @RequestParam(name = "contenido") String contenido,
								 @RequestParam(name = "tipoevaluacion") String tipoevaluacion,
								 @RequestParam(name = "evaluacioncontinua") String evaluacioncontinua,
								 @RequestParam(name = "evaluacionperiodica") String evaluacionperiodica,
								 @RequestParam(name = "instrumentos") String instrumentos,
								 @RequestParam(name = "requisitos") String requisitos*/) throws SQLException
    {
    	//Silabus silabo = new Silabus(Integer.parseInt(id_asignatura), semestre, contenido, tipoevaluacion, evaluacioncontinua,evaluacionperiodica,instrumentos,requisitos);
    	System.out.println("asdasd  "+foreignkey);
    	//Application.silaboDAO.insert(silabo);
        return "redirect:index.html";
    }
    
    @RequestMapping(method = {RequestMethod.POST, RequestMethod.GET}, value = "/registerCronograma")
    public String registerCronograma(@RequestParam(name = "id_asignatura") String id_asignatura,
    							  @RequestParam(name = "P1") String P1,
    							  @RequestParam(name = "P2") String P2,
    							  @RequestParam(name = "F") String F) throws SQLException
    {
    	String semana=P1+" "+P2+" "+F;
    	Cronograma cronograma = new Cronograma(Integer.parseInt(id_asignatura), semana);
    	Application.cronogramaDAO.insert(cronograma);
        return "redirect:index.html";
    }
    
    @RequestMapping(method = {RequestMethod.POST, RequestMethod.GET}, value = "/registerCompetencias")
    public String registerCompetencias(@RequestParam(name = "nombre") String nombre,
    							  @RequestParam(name = "nivel") String nivel,
    							  @RequestParam(name = "idresultados") String idresultados,
    							  @RequestParam(name = "idsilabos") String idsilabos) throws SQLException
    {
    	Competencias competencias = new Competencias(nombre,Integer.parseInt(nivel),Integer.parseInt(idresultados),Integer.parseInt(idsilabos));
    	Application.competenciasDAO.insert(competencias);
        return "redirect:index.html";
    }
    
    @RequestMapping(method = {RequestMethod.POST, RequestMethod.GET}, value = "/registerResultados")
    public String registerResultados(@RequestParam(name = "descripcion") String descripcion) throws SQLException
    {
    	Resultados resultados = new Resultados(descripcion);
    	Application.resultadosDAO.insert(resultados);
        return "redirect:index.html";
    }
}
