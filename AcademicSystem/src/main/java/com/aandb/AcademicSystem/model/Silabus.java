package com.aandb.AcademicSystem.model;

public class Silabus {
	private int id;
	private int id_asignatura;
	private String semestre;
	private String contenido;
	private String tipos_evaluacion;
	private String evaluacion_continua;
	private String evaluacion_periodica;
	private String instrumentos;
	private String requisitos_evaluacion;
	
	public Silabus() {}
	
	public Silabus(int id_asignatura, String semestre, String contenido, String tipos_evaluacion,
			String evaluacion_continua, String evaluacion_periodica, String instrumentos,
			String requisitos_evaluacion) {
		this.id_asignatura = id_asignatura;
		this.semestre = semestre;
		this.contenido = contenido;
		this.tipos_evaluacion = tipos_evaluacion;
		this.evaluacion_continua = evaluacion_continua;
		this.evaluacion_periodica = evaluacion_periodica;
		this.instrumentos = instrumentos;
		this.requisitos_evaluacion = requisitos_evaluacion;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getId_asignatura() {
		return id_asignatura;
	}

	public void setId_asignatura(int id_asignatura) {
		this.id_asignatura = id_asignatura;
	}

	public String getSemestre() {
		return semestre;
	}

	public void setSemestre(String semestre) {
		this.semestre = semestre;
	}

	public String getContenido() {
		return contenido;
	}

	public void setContenido(String contenido) {
		this.contenido = contenido;
	}

	public String getTipos_evaluacion() {
		return tipos_evaluacion;
	}

	public void setTipos_evaluacion(String tipos_evaluacion) {
		this.tipos_evaluacion = tipos_evaluacion;
	}

	public String getEvaluacion_continua() {
		return evaluacion_continua;
	}

	public void setEvaluacion_continua(String evaluacion_continua) {
		this.evaluacion_continua = evaluacion_continua;
	}

	public String getEvaluacion_periodica() {
		return evaluacion_periodica;
	}

	public void setEvaluacion_periodica(String evaluacion_periodica) {
		this.evaluacion_periodica = evaluacion_periodica;
	}

	public String getInstrumentos() {
		return instrumentos;
	}

	public void setInstrumentos(String instrumentos) {
		this.instrumentos = instrumentos;
	}

	public String getRequisitos_evaluacion() {
		return requisitos_evaluacion;
	}

	public void setRequisitos_evaluacion(String requisitos_evaluacion) {
		this.requisitos_evaluacion = requisitos_evaluacion;
	}
	
	
	
}
