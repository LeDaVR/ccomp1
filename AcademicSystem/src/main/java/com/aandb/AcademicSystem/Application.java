package com.aandb.AcademicSystem;

import java.sql.SQLException;

import javax.annotation.PreDestroy;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;


import com.aandb.AcademicSystem.dao.StudentDAO;
import com.aandb.AcademicSystem.dao.SubjectDAO;
import com.aandb.AcademicSystem.dao.SilabusDAO;
import com.aandb.AcademicSystem.dao.CronogramaDAO;
import com.aandb.AcademicSystem.dao.CompetenciasDAO;
import com.aandb.AcademicSystem.dao.ResultadosDAO;

@SpringBootApplication
public class Application
{
    private static ConfigurableApplicationContext context;
    public static SilabusDAO silaboDAO;
    public static StudentDAO studentDAO;
    public static SubjectDAO subjectDAO;
    public static CronogramaDAO cronogramaDAO;
    public static CompetenciasDAO competenciasDAO;
    public static ResultadosDAO resultadosDAO;
    
    public static void main(String[] args)
    {
        String jdbcURL = "jdbc:mysql://localhost:3306/academicSystemDB";
        String jdbcUsername = "root";
        String jdbcPassword = "root";
        
        try
        {
        	silaboDAO = new SilabusDAO(jdbcURL, jdbcUsername, jdbcPassword);
            studentDAO = new StudentDAO(jdbcURL, jdbcUsername, jdbcPassword);
            subjectDAO = new SubjectDAO(jdbcURL, jdbcUsername, jdbcPassword);
            cronogramaDAO = new CronogramaDAO(jdbcURL, jdbcUsername, jdbcPassword);
            competenciasDAO = new CompetenciasDAO(jdbcURL, jdbcUsername, jdbcPassword);
            resultadosDAO = new ResultadosDAO(jdbcURL, jdbcUsername, jdbcPassword);
        }
        catch(SQLException e)
        {
            System.out.println("Failed to initialize the DAOs!");
        }
        System.out.println("--------------------------------------------------------------------------");
        System.out.println("CONNECTION SUCCESS! Done At: " + jdbcURL);
        System.out.println("--------------------------------------------------------------------------");
        context = SpringApplication.run(Application.class, args);
    }
    
    @PreDestroy
    public void onShutDown()
    {
        context.close();
        System.out.println("Closing safety . . .");
    }
}
