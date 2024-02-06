#include <curl/curl.h>
#include <string.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("%s URL\n", argv[0]);
    return 1;
  }

  CURL *checker = curl_easy_init();
  char *redirect_url;
  int eval = 1;

  curl_easy_setopt(checker, CURLOPT_URL, argv[1]);
  curl_easy_setopt(checker, CURLOPT_NOBODY, 1L);
  curl_easy_setopt(checker, CURLOPT_USERAGENT, "httpsredirectchecker/1.0");

  curl_easy_perform(checker);

  curl_easy_getinfo(checker, CURLINFO_REDIRECT_URL, &redirect_url);

  eval = (redirect_url && strncmp(redirect_url, "https", 5) == 0) ? 0 : 1;

  curl_easy_cleanup(checker);

  if (eval) {
    printf("%s: No https redirect\n", argv[1]);
  }

  return eval;
}
