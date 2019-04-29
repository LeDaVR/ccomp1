void glAccum(GLenum op,GLfloat value);
// op = especifica la operacion del buffer de acumulacion, acepta (GL_ACCUM, GL_LOAD, GL_ADD, GL_MULT, , GL_RETURN ) 
// value =especifica el valor del GLfloat que es usada en la operacion, op determinna como se usa este valor
//al parecer mezlca colores
--colores
GL_ACCUM_RED_BITS
GL_ACCUM_GREEN_BITS
GL_ACCUM_BLUE_BITS
GL_ACCUM_ALPHA_BITS
--------------------------------
--OPERACIONES
GL_ACCUM
//divide entre 2n-1 al color y lo multiplica por value y almacena al bufeer de acumulacion 
GL_LOAD
//parecido a accum -probar
GL_ADD
// agrega valor al buffer de acumulacion
GL_MULT
// multiplica un valor al buffer de acumulacion
GL_RETURN
// solo se aplica a pixel ownership, scissor, dithering, and color writemasks.
glGet--------------------------------
void glGetBooleanv(GLenum pname,GLboolean * params);
void glGetDoublev(GLenum pname,GLdouble * params);
void glGetFloatv(GLenum pname,GLfloat * params);
void glGetIntegerv(	GLenum pname,GLint * params);
// pname = esperecifica que valor sera retornado tambien acapta las siguientes constantes en https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glGet.xml

// params = retorna el valor o valores con parametros especificados

GLuint glCreateShader(GLenum shaderType);
//retorna un unsigned int diferente de 0 mediante el cual puede ser referenciado
//shaderType = puede ser GL_VERTEX_SHADER o GL_FRAGMENT_SHADER
void glShaderSource(GLuint shader,GLsizei count,const GLchar **string,const GLint *length);
//replaza el valor de un shader por el el codigo cargado
// shader = especifica el shader al cual se le va a remplazar el valor
//count = especifica el numero de string
//string = especifica la direccion del arreglo de caracteres para cargar al shader
//lenght = especifica un arreglo con los tamaños de los string, si es NULL significa que string debe terminar en \0
void glCompileShader(GLuint shader)
// compila el string de shader
void glGetShaderiv(	GLuint shader,GLenum pname,GLint *params);
// recibe un shader y comprueba un estado llamado pname y el resultado lo almacena en params
//lo que pname acepta son:
GL_SHADER_TYPE  // retorna GL_VERTEX_SHADER o  GL_FRAGMENT_SHADER dependiendo del tipo de shader
GL_DELETE_STATUS   //  retorna GL_TRUE o GL_FALSE
GL_COMPILE_STATUS  //  retorna GL_TRUE o GL_FALSE
GL_INFO_LOG_LENGTH   //  retorna el largo de info_log si no hay retorna 0
GL_SHADER_SOURCE_LENGTH  // devuelve el tamaño del string del shader incluido el caracter nulo si no exite retorna 0
 
