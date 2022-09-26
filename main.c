#include "httpd.h"

int main(int c, char** v)
{
    serve_forever("12913");
    return 0;
}

void route()
{
    ROUTE_START()

    ROUTE_GET("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Hello! You are using %s", request_header("User-Agent"));
    }

    ROUTE_POST("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Wow, seems that you POSTed %d bytes. \r\n", payload_size);
        printf("Fetch the data using `payload` variable.");
    }
  
    ROUTE_END()
}

// void route()
// {
//     if (0) {} 
//     else if (strcmp(URI,uri)==0&&strcmp(METHOD,method)==0) {{
//         printf("HTTP/1.1 200 OK\r\n\r\n");
//         printf("Hello! You are using %s", request_header("User-Agent"));
//     }
//     else if (strcmp(URI,uri)==0&&strcmp(METHOD,method)==0) {
//         printf("HTTP/1.1 200 OK\r\n\r\n");
//         printf("Wow, seems that you POSTed %d bytes. \r\n", payload_size);
//         printf("Fetch the data using `payload` variable.");
//     }
//     else printf(\
//         "HTTP/1.1 500 Not Handled\r\n\r\n" \
//         "The server has no handler to the request.\r\n" \
//     );
// }