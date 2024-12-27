/* Determine if the sex of the offspring will be male or female based 
 * on the X or Y chromosome present in the male's sperm.
If the sperm contains the X chromosome, return "Congratulations! You're
going to have a daughter."; If the sperm contains the Y chromosome, return 
"Congratulations! You're going to have a son."; */
const char *chromosomeCheck(const char chromosomes[2 + 1]) {
		return chromosomes[0] == 'X' && chromosomes[1] == 'X' ? "Congratulations! You're going to have a daughter." : "Congratulations! You're going to have a son.";
}
