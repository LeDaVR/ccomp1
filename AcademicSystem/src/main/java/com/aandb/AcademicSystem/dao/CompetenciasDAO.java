package com.aandb.AcademicSystem.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import com.aandb.AcademicSystem.model.Competencias;
import com.aandb.AcademicSystem.model.DBConnection;

public class CompetenciasDAO {
	private DBConnection dbConnection;
    private Connection connection;
    
    public CompetenciasDAO(String jdbcURL, String jdbcUsername, String jdbcPassword) throws SQLException
    {
        dbConnection = new DBConnection(jdbcURL, jdbcUsername, jdbcPassword);
    }
    
    public boolean insert(Competencias competencias) throws SQLException
    {
    	int nextId=0;
    	String sql = "SELECT * FROM competencias";
        dbConnection.connect();
        connection = dbConnection.getJdbcConnection();
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(sql);
        
        while(resultSet.next())
        {
            nextId = resultSet.getInt("id");
        }
        
        String sqlinsert = "INSERT INTO competencias VALUES (?,?,?,?,?,?)";
        dbConnection.connect();
        connection = dbConnection.getJdbcConnection();
        PreparedStatement statementinsert = connection.prepareStatement(sqlinsert);
        statementinsert.setInt(1,nextId+1);
        statementinsert.setString(2, competencias.getNombre());
        statementinsert.setInt(3, competencias.getNivel());
        statementinsert.setInt(5, competencias.getIdresultados());
        statementinsert.setInt(6, competencias.getIdsilabo());
        
        boolean rowInserted = statementinsert.executeUpdate() > 0;
        statement.close();
        dbConnection.disconnect();
        return rowInserted;
    }
}
