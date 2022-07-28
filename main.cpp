#include <git2.h>
#include <iostream> 

int creds(git_cred **out, const char *url, const char *username_from_url,
             unsigned int allowed_types, void *payload) {
    std::cout << "Calling creds" << std::endl;
    return git_credential_ssh_key_new(out, username_from_url,
           "/Users/luclambour/.ssh/id_rsa_github.pub", "/Users/luclambour/.ssh/id_rsa_github", "");
}

int main() {
    git_libgit2_init();
    std::string url = "git@github.com:Lambourl/git-test-clone.git";

    git_repository *repo = nullptr;
    git_clone_options ops = GIT_CLONE_OPTIONS_INIT;
    ops.fetch_opts.callbacks.credentials = creds;

    int err = git_clone(&repo, url.c_str(), "/Users/luclambour/workspace/exp/try_uc/luc", &ops);
    std::cout << giterr_last()->message << std::endl;

    git_libgit2_shutdown();
    return 0;
}