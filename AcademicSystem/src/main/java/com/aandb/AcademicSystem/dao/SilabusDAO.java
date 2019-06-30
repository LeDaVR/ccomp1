package com.aandb.AcademicSystem.dao;


import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import com.aandb.AcademicSystem.model.Silabus;
import com.aandb.AcademicSystem.model.DBConnection;

public class SilabusDAO {
	private DBConnection dbConnection;
    private Connection connection;

    public SilabusDAO(String jdbcURL, String jdbcUsername, String jdbcPassword) throws SQLException
    {
        dbConnection = new DBConnection(jdbcURL, jdbcUsername, jdbcPassword);
    }
    
    public boolean insert(Silabus silabo) throws SQLException
    {
    	int nextId=0;
    	String sql = "SELECT * FROM silabo";
        dbConnection.connect();
        connection = dbConnection.getJdbcConnection();
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(sql);
        
        while(resultSet.next())
        {
            nextId = resultSet.getInt("id");
        }
        
        dbConnection.disconnect();
        
        String sqlinsert = "INSERT INTO silabo VALUES (?,?,?,?, ?, ?, ?, ?, ?)";
        dbConnection.connect();
        connection = dbConnection.getJdbcConnection();
        PreparedStatement statementinsert = connection.prepareStatement(sqlinsert);
        statementinsert.setInt(1,nextId+1);
        statementinsert.setInt(2, silabo.getId_asignatura());
        statementinsert.setString(3, silabo.getSemestre());
        statementinsert.setString(4, silabo.getContenido());
        statementinsert.setString(5, silabo.getTipos_evaluacion());
        statementinsert.setString(6, silabo.getEvaluacion_continua());
        statementinsert.setString(7, silabo.getEvaluacion_periodica());
        statementinsert.setString(8, silabo.getInstrumentos());
        statementinsert.setString(9, silabo.getRequisitos_evaluacion());
        
        boolean rowInserted = statementinsert.executeUpdate() > 0;
        statement.close();
        dbConnection.disconnect();
        return rowInserted;
    }
    
    public List<Silabus> listSilabos() throws SQLException
    {
        List<Silabus> listSilabos = new ArrayList<Silabus>();
        String sql = "SELECT * FROM silabo";
        dbConnection.connect();
        connection = dbConnection.getJdbcConnection();
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(sql);
        
        while(resultSet.next())
        {
            int id_asignatura = resultSet.getInt("id_asignatura");
            String contenido = resultSet.getString("contenido");
            String semestre = resultSet.getString("semestre");
            String tipo_evaluacion = resultSet.getString("tipos_evaluacion");
            String evaluacioncontinua = resultSet.getString("evaluacion_continua");
            String evaluacionperiodica = resultSet.getString("evaluacion_periodica");
            String instrumentos = resultSet.getString("instrumentos");
            String requisitos_evaluacion = resultSet.getString("requisitos_evaluacion");
            Silabus silabo = new Silabus();
            silabo.setId_asignatura(id_asignatura);
            silabo.setContenido(contenido);
            silabo.setSemestre(semestre);
            silabo.setTipos_evaluacion(tipo_evaluacion);
            silabo.setEvaluacion_continua(evaluacioncontinua);
            silabo.setEvaluacion_periodica(evaluacionperiodica);
            silabo.setInstrumentos(instrumentos);
            silabo.setRequisitos_evaluacion(requisitos_evaluacion);
            
            listSilabos.add(silabo);
        }
        
        dbConnection.disconnect();
        return listSilabos;
    }
    
    public Silabus getStudentByAsignatura(int id_asignatura) throws SQLException
    {
        Silabus silabo = new Silabus();
        
        String sql = "SELECT * FROM silabo WHERE id_asignatura=?";
        dbConnection.connect();
        connection = dbConnection.getJdbcConnection();
        PreparedStatement statement = connection.prepareStatement(sql);
        statement.setInt(1, id_asignatura);
        
        ResultSet res = statement.executeQuery();
        if(res.next())
        {
            silabo.setId_asignatura(res.getInt("id_asignatura"));
            silabo.setContenido(res.getString("contenido"));
            silabo.setSemestre(res.getString("semestre"));
            silabo.setTipos_evaluacion(res.getString("tipo_evaluacion"));
            silabo.setEvaluacion_continua(res.getString("evaluacioncontinua"));
            silabo.setEvaluacion_periodica(res.getString("evaluacionperiodica"));
            silabo.setInstrumentos(res.getString("instrumentos"));
            silabo.setRequisitos_evaluacion(res.getString("requisitos_evaluacion"));
        }
        res.close();
        dbConnection.disconnect();
        
        return silabo;
    }
    
    /*public boolean update(Silabo silabo) throws SQLException
    {
        String sql = "UPDATE silabo SET nombre=?, apellidos=?, edad=?, sexo=? WHERE id_asignatura=?";
        dbConnection.connect();
        connection = dbConnection.getJdbcConnection();
        PreparedStatement statement = connection.prepareStatement(sql);
        statement.setString(1, student.getName());
        statement.setString(2, student.getLastName());
        statement.setInt(3, student.getAge());       
        statement.setString(4, student.getSex());
        statement.setInt(5, student.getCui());
        
        boolean rowUpdated = statement.executeUpdate() > 0;
        statement.close();
        dbConnection.disconnect();
        return rowUpdated;
    }
    
    public boolean delete(Silabo silabo) throws SQLException
    {
        String sql = "DELETE FROM alumno WHERE cui=?";
        dbConnection.connect();
        connection = dbConnection.getJdbcConnection();
        PreparedStatement statement = connection.prepareStatement(sql);
        statement.setInt(1, student.getCui());
        
        boolean rowDeleted = statement.executeUpdate() > 0;
        statement.close();
        dbConnection.disconnect();
        return rowDeleted;
    }*/
}
