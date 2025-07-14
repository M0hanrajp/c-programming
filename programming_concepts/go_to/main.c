/* A sample program to understand goto statement 
 * Entire program is just a simulation
 * */
#include <stdio.h>
#include <stdbool.h>
#define MAX_RETRY 5

bool attemptConnection(void) {
    printf("[%s]Connecting\n", __func__);
    return true;
}

bool attemptAuthentication(int *retryCount) {
    // some authentication
    if(*retryCount < MAX_RETRY) 
        (*retryCount)++;
    else 
        return false;
    return true;
};

bool attemptDataTransfer(void) {
    printf("[%s] sending data packet\n", __func__);
    return true;
}

int main(void) {
    goto startProtocol;

    startProtocol:
        printf("[%s]Protocol Initialization ...\n", __func__);
        bool connOK = false;
        bool authOK = false;
        bool dataOK = false;
        int  retryCount = 0;
        goto connectStage;

    connectStage:
        /* connect something example: (like call a function and make connection)
         * and set connOK to true; for this example consider it was done
         */
        connOK = attemptConnection();
        if(connOK) {
            printf("[%s] connection success\n", __func__);
            goto authenticationStage;
        } else
            goto ERROR_STAGE;

    authenticationStage:
        while(true) {
            authOK = attemptAuthentication(&retryCount);
            if(authOK) {
                printf("[%s] Authentication succesful, number of auth requests: %d\n", 
                        __func__, retryCount);
                goto transferStage;
            } else if(retryCount < MAX_RETRY) {
                continue;
            } else {
                printf("[%s] Authentication failed, number of auth requests: %d\n", 
                       __func__, retryCount);
                goto ERROR_STAGE;
            }
        }

    transferStage:
        dataOK = attemptDataTransfer();
        if(dataOK) {
            printf("[%s] Data sent successfully\n", __func__);
            goto completeStage;
        } else {
            goto ERROR_STAGE;
        }

    completeStage:
        printf("[%s] protocol processed data packet\n", __func__);
        goto SUCCESS;

    ERROR_STAGE:
        printf("[%s] protocol failed, exit\n", __func__);
        return -1;

    SUCCESS:
    return 0;
}
