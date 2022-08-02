#include <git2.h>
#include <iostream> 

int main() {
    git_libgit2_init();
    std::string url = "http://github.com/Lambourl/git-test-clone.git";
    std::string path_copy= "/Users/luclambour/workspace/repo_test_libgit/marie";
    git_repository *repo = nullptr;
    git_libgit2_opts(GIT_OPT_SET_SSL_CERT_LOCATIONS, "/private/etc/ssl/cert.pem",nullptr);
    int err = git_clone(&repo, url.data(), path_copy.data(), NULL);
    std::cout << giterr_last()->message << std::endl;
    git_libgit2_shutdown();
    return 0;
}