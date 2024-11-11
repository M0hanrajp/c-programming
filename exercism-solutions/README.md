### Fix x509 certificate error

- Follow [guide to solving exercises locally to install exercism cli and configure your token](https://exercism.org/docs/using/solving-exercises/working-locally)
- if you encounter the following error while configuring your token (as below error):
```bash
mpunix@LIN-5CG3350MRD:~$ exercism configure --token=<your token> -v

========================= BEGIN DumpRequest =========================
GET /v1/ping HTTP/1.1
Host: api.exercism.io
Content-Type: application/json
User-Agent: github.com/exercism/cli v3.5.2 (linux/amd64)


========================= END DumpRequest =========================

Error: The base API URL 'https://api.exercism.io/v1' cannot be reached.

Get "https://api.exercism.io/v1/ping": tls: failed to verify certificate: x509: certificate signed by unknown authority
```
### Solution:
- Run the following command:
```bash
sudo apt update && sudo apt install --reinstall ca-certificates
```
- if it does not work then try running `curl -L -k https://api.exercism.io/v1/ping` should output something as
```bash
mpunix@LIN-5CG3350MRD:~/exercism$ curl -L -k https://api.exercism.io/v1/ping
{"status":{"website":true,"database":true}}
```
- If this works, it indicates the issue is with certificate verification.

Now, Since -k worked, manually installing Exercism's SSL certificate as a trusted certificate should allow the Exercism CLI to connect securely.
- Download and add the certificate
```bash
echo | openssl s_client -showcerts -servername api.exercism.io -connect api.exercism.io:443 2>/dev/null | openssl x509 -outform PEM > exercism.crt
sudo mv exercism.crt /usr/local/share/ca-certificates/
sudo update-ca-certificates
```
- Verify the installation by retrying `curl -L https://api.exercism.io/v1/ping` without `-k`.

This Will fix the issue, continue configuring your exercism token again.

### Configure Github contributions 

If you want to show case your solved problems on github then follow the below steps.
- Inititally setup a github repo with the name of your choice.
- Clone your repository to your local machine to your `<path>`.
- Now use the following command:
```bash
~$ exercism configure --token=<your token> --workspace=<path to your github folder in your machine>
```
- You will see below details after executing:
```bash
You have configured the Exercism command-line client:

Config dir:                       <installed path of exercism executable>
Token:         (-t, --token)      <configured token>
Workspace:     (-w, --workspace)  <path to your workspace i.e. your github cloned folder>
API Base URL:  (-a, --api)        https://api.exercism.io/v1
```
Now you can use exercism to solve problems locally and use git commands to upload your solutions to your repository.
