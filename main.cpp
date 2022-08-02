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
    git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;
    //git_clone_options clone_opts;
    //git_clone_init_options(&clone_opts, GIT_CLONE_OPTIONS_VERSION);

    clone_opts.fetch_opts.callbacks.credentials = creds;
    //clone_opts.fetch_opts.proxy_opts.type = GIT_PROXY_NONE;
    git_proxy_options_init(&(clone_opts.fetch_opts.proxy_opts), 1);
    clone_opts.checkout_opts.checkout_strategy = GIT_CHECKOUT_SAFE;
    clone_opts.checkout_opts.progress_payload = nullptr;
    clone_opts.fetch_opts.callbacks.payload = nullptr;
    int err = 1;

    err = git_clone(&repo, url.c_str(), "/Users/luclambour/workspace/repo_test_libgit/luc", &clone_opts);
    std::cout << giterr_last()->message << std::endl;

    git_libgit2_shutdown();
    return 0;
}