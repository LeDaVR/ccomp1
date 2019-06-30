package com.aandb.AcademicSystem.model;

public class Competencias {
	private int id;
	private String nombre;
	private int nivel;
	private int idresultados;
	private int idsilabo;
	
	public Competencias() {}
	public Competencias(String nombre, int nivel, int idresultados, int idsilabo) {
		this.nombre = nombre;
		this.nivel = nivel;
		this.idresultados = idresultados;
		this.idsilabo = idsilabo;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public int getNivel() {
		return nivel;
	}
	public void setNivel(int nivel) {
		this.nivel = nivel;
	}
	public int getIdresultados() {
		return idresultados;
	}
	public void setIdresultados(int idresultados) {
		this.idresultados = idresultados;
	}
	public int getIdsilabo() {
		return idsilabo;
	}
	public void setIdsilabo(int idsilabo) {
		this.idsilabo = idsilabo;
	}
	
	
	
}
