package com.aandb.AcademicSystem.model;

public class Cronograma {
	int id;
	int id_silabo;
	String semana;
	
	public Cronograma() {}
	public Cronograma(int id_silabo, String semana) {
		this.id_silabo = id_silabo;
		this.semana = semana;
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public int getId_silabo() {
		return id_silabo;
	}
	public void setId_silabo(int id_silabo) {
		this.id_silabo = id_silabo;
	}
	public String getSemana() {
		return semana;
	}
	public void setSemana(String semana) {
		this.semana = semana;
	}
	
	
}
