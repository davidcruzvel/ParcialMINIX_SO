#include "headers.h" // declaraciones y prototipos
#include "fshell.h"

int main(int argc, char **argv, char **envp)
{
		init();
		char user[20];
		char pass[20];
		int i;
		fflush(stdin);
		printf("Usuario: ");
		gets(user);
		printf("\nContra: ");
		fflush(stdin);
		gets(pass);

		printf("\n");
		if(Login(user,pass) == 1){
			pantallaBienvenida();
	        shellPrompt();    // muestra el prompt
	        while (TRUE) {
	                entradaUsuario = getchar();
	                switch (entradaUsuario) {
	                case '\n':   // si el usuario solo presiona enter

	                    shellPrompt();   // no pasa nada
	                    break;
	                default:
	                        getLineaTexto();     // almacena la entrada de usuario en el buffer
	                        manejarComandoUsuario(); // ejecuta el comando de usuario
	                        shellPrompt();  // muestra el prompt
	                        break;
	                }
	        }
	        printf("\n");
		}else{
			printf("\nUsuario o contrasenia incorrectos\n");
		}
        return 0;
}
