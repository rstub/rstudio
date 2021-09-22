/*
 * SessionOptions.gen.hpp
 *
 * Copyright (C) 2021 by RStudio, PBC
 *
 * Unless you have received this program directly from RStudio pursuant
 * to the terms of a commercial license agreement with RStudio, then
 * this program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */

// THIS FILE WAS AUTOMATICALLY GENERATED BY A TOOL - DO NOT HAND EDIT IT

#ifndef SESSION_SESSION_OPTIONS_GEN_HPP
#define SESSION_SESSION_OPTIONS_GEN_HPP

#include <string>
#include <map>
#include <shared_core/FilePath.hpp>
#include <core/ProgramOptions.hpp>
#include <core/system/Xdg.hpp>
#include <session/SessionConstants.hpp>
#include <core/http/Request.hpp>
#include <core/http/Cookie.hpp>


namespace rstudio {
namespace session {

class GeneratedOptions
{
public:
   virtual ~GeneratedOptions() {}
   virtual core::ProgramStatus read(int argc,
                                    char * const argv[],
                                    std::ostream& osWarnings) = 0;

protected:
   rstudio::core::program_options::OptionsDescription
   buildOptions(boost::program_options::options_description* pTests,
                boost::program_options::options_description* pScript,
                boost::program_options::options_description* pVerify,
                boost::program_options::options_description* pVersion,
                boost::program_options::options_description* pProgram,
                boost::program_options::options_description* pLog,
                boost::program_options::options_description* pDocs,
                boost::program_options::options_description* pWww,
                boost::program_options::options_description* pSession,
                boost::program_options::options_description* pAllow,
                boost::program_options::options_description* pR,
                boost::program_options::options_description* pLimits,
                boost::program_options::options_description* pExternal,
                boost::program_options::options_description* pGit,
                boost::program_options::options_description* pUser,
                boost::program_options::options_description* pMisc,
                std::string* pSaveActionDefault,
                int* wwwSameSite)
{
   using namespace rstudio::core;
   using namespace boost::program_options;

   pTests->add_options()
      (kRunTestsSessionOption,
      value<bool>(&runTests_)->default_value(false)->implicit_value(true),
      "Runs unit tests and exits.");

   pScript->add_options()
      (kRunScriptSessionOption,
      value<std::string>(&runScript_)->default_value(std::string()),
      "Runs an R script and exits.");

   pVerify->add_options()
      (kVerifyInstallationSessionOption,
      value<bool>(&verifyInstallation_)->default_value(false),
      "Verifies that the session installation is working correctly and exits.");

   pVersion->add_options()
      (kVersionSessionOption,
      value<bool>(&version_)->default_value(false)->implicit_value(true),
      "Prints the version number and exits.");

   pProgram->add_options()
      (kProgramModeSessionOption,
      value<std::string>(&programMode_)->default_value("server"),
      "The program mode the session is running in (desktop or server).");

   pLog->add_options()
      ("log-stderr",
      value<bool>(&logStderr_)->default_value(false),
      "Writes log entries to stderr in addition to any other configured log destinations.");

   pDocs->add_options()
      ("docs-url",
      value<std::string>(&docsURL_)->default_value(std::string()),
      "If specified, overrides the URL to navigate to when a user clicks on the RStudio help link.");

   pWww->add_options()
      ("www-local-path",
      value<std::string>(&wwwLocalPath_)->default_value("www"),
      "The relative path from the RStudio installation directory, or absolute path where web assets are stored.")
      ("www-symbol-maps-path",
      value<std::string>(&wwwSymbolMapsPath_)->default_value("www-symbolmaps"),
      "The relative path from the RStudio installation directory, or absolute path, where symbol maps are stored.")
      (kWwwPortSessionOption,
      value<std::string>(&wwwPort_)->default_value("8787"),
      "The HTTP port to listen on for incoming connections. This is generally only used with Launcher sessions.")
      (kWwwAddressSessionOption,
      value<std::string>(&wwwAddress_)->default_value("127.0.0.1"),
      "The address to listen on for incoming connections. This is generally only used with Launcher sessions.")
      (kStandaloneSessionOption,
      value<bool>(&standalone_)->default_value(false),
      "Runs the session in standalone mode, indicating we should use HTTP communication. This is generally only used with Launcher sessions.")
      (kVerifySignaturesSessionOption,
      value<bool>(&verifySignatures_)->default_value(false),
      "Indicates whether or not to verify signatures on incoming requests. This is generally only used with Launcher sessions.")
      (kWwwResusePorts,
      value<bool>(&wwwReusePorts_)->default_value(false),
      "Whether or not to reuse last used bound ports when restarting a Launcher session.");

   pSession->add_options()
      (kTimeoutSessionOption,
      value<int>(&timeoutMinutes_)->default_value(120),
      "The amount of minutes before a session times out, at which point the session will either suspend or exit.")
      (kTimeoutSuspendSessionOption,
      value<bool>(&timeoutSuspend_)->default_value(true),
      "Indicates whether or not to suspend the session after the timeout has elapsed. Setting this to `false` will cause the session to quit instead of suspending to disk when the session times out.")
      (kDisconnectedTimeoutSessionOption,
      value<int>(&disconnectedTimeoutMinutes_)->default_value(0),
      "If set, causes the session to time out after not receiving any new connections within the specified minutes. This behavior is generally not needed, and you should instead use session-timeout-minutes")
      ("session-preflight-script",
      value<std::string>(&preflightScriptPath_)->default_value(std::string()),
      "Sets a script to be run on startup before any R initialization has occurred.")
      ("session-create-public-folder",
      value<bool>(&createPublicFolder_)->default_value(false),
      "Indicates whether or not to create a `Public` folder for the user whenever the session starts. This folder will have global read permissions, and can be used as a simple means for users to share files. It is recommended you do not use this feature, and instead use the more advanced Project Sharing features.")
      ("session-create-profile",
      value<bool>(&createProfile_)->default_value(false),
      "Indicates whether or not to create a default empty .Rprofile script within the user's home directory, which can be altered to perform any desired common startup tasks.")
      ("session-rprofile-on-resume-default",
      value<bool>(&rProfileOnResumeDefault_)->default_value(false),
      "Specifies the default user setting for running the Rprofile when sessions are resumed.")
      ("session-save-action-default",
      value<std::string>(pSaveActionDefault)->default_value(std::string()),
      "Specifies the default save action (yes, no, or ask).")
      ("session-default-working-dir",
      value<std::string>(&defaultWorkingDir_)->default_value(std::string()),
      "Specifies the default working directory to use for new sessions.")
      ("session-default-new-project-dir",
      value<std::string>(&deprecatedDefaultProjectDir_)->default_value("~"),
      "Specifies the default directory to use for new projects.")
      ("show-help-home",
      value<bool>(&showHelpHome_)->default_value(false),
      "Indicates whether or not to show the help home page on startup.")
      ("session-default-console-term",
      value<std::string>(&defaultConsoleTerm_)->default_value("xterm-256color"),
      "Specifies the default TERM setting for the R console.")
      ("session-default-clicolor-force",
      value<bool>(&defaultCliColorForce_)->default_value(true),
      "Specifies the default CLICOLOR_FORCE setting for the R console.")
      ("session-quit-child-processes-on-exit",
      value<bool>(&quitChildProcessesOnExit_)->default_value(false),
      "Indicates whether or not to quit child processes of the session on exit. If unset, child processes created by forking or parallel processing may continue to run in the background after the session is terminated.")
      ("session-first-project-template-path",
      value<std::string>(&firstProjectTemplatePath_)->default_value(std::string()),
      "Specifies the path to a first project template which will be copied into new users' home directories and opened the first time they run a session. The template can optionally be configured with `DefaultOpenDocs` to cause documents to automatically be opened for the first project.")
      ("default-rsconnect-server",
      value<std::string>(&defaultRSConnectServer_)->default_value(std::string()),
      "Specifies the default RStudio Connect server URL.")
      (kTerminalPortOption,
      value<std::string>(&terminalPort_)->default_value(std::string()),
      "If specified, sets the port to bind the terminal server to. This should generally only be set for containerized Launcher sessions, where the port must be known.")
      (kWebSocketPingInterval,
      value<int>(&webSocketPingSeconds_)->default_value(10),
      "Specifies the WebSocket keep-alive ping interval for session terminals.")
      (kWebSocketConnectTimeout,
      value<int>(&webSocketConnectTimeout_)->default_value(3),
      "Specifies the WebSocket initial connection timeout in seconds for session terminals.")
      (kWebSocketLogLevel,
      value<int>(&webSocketLogLevel_)->default_value(0),
      "Specifies the WebSocket log level for session terminals ((0=none, 1=errors, 2=activity, 3=all).")
      (kWebSocketHandshakeTimeout,
      value<int>(&webSocketHandshakeTimeoutMs_)->default_value(5000),
      "Specifies the WebSocket protocol handshake timeout for session terminals in milliseconds.")
      (kPackageOutputInPackageFolder,
      value<bool>(&packageOutputToPackageFolder_)->default_value(false),
      "Specifies whether or not package builds output to the package project folder.")
      (kRootPathSessionOption,
      value<std::string>(&rootPath_)->default_value(kRequestDefaultRootPath),
      "The path prefix added by a proxy to the incoming RStudio URL. This setting is used so RStudio Server knows what path it is being served from. If running RStudio Server behind a path-modifying proxy, this should be changed to match the base RStudio Server URL.")
      (kUseSecureCookiesSessionOption,
      value<bool>(&useSecureCookies_)->default_value(false),
      "Indicates whether or not to mark cookies as secure.")
      (kSameSiteSessionOption,
      value<int>(wwwSameSite)->default_value(0),
      "The value of the SameSite attribute used in cookie issued by the session.")
      ("restrict-directory-view",
      value<bool>(&restrictDirectoryView_)->default_value(false),
      "Indicates whether or not to restrict the directories that can be viewed within the IDE.")
      ("directory-view-allow-list",
      value<std::string>(&directoryViewAllowList_)->default_value(std::string()),
      "Specifies a list of directories exempt from directory view restrictions, separated by a colon character (:).")
      (kSessionEphemeralEnvVars,
      value<std::string>(&ephemeralEnvVars_)->default_value(std::string()),
      "Specifies a list of environment variables that will not be saved when sessions suspend, separated by a colon character (:).")
      (kSessionSuspendOnIncompleteStatement,
      value<bool>(&suspendOnIncompleteStatement_)->default_value(false),
      "Specifies whether the session should be allowed to suspend when a user has entered a partial R statement.")
      (kSessionAsyncRpcEnabled,
      value<bool>(&asyncRpcEnabled_)->default_value(true),
      "Enables async responses to rpc requests to prevent connection logjams in the browser, allowing interrupt of busy sessions")
      (kSessionAsyncRpcTimeoutMs,
      value<int>(&asyncRpcTimeoutMs_)->default_value(200),
      "Duration in millis before requests are converted to async - i.e. how fast will the server free up connections when it's busy")
      (kSessionHandleOfflineEnabled,
      value<bool>(&handleOfflineEnabled_)->default_value(true),
      "Enables offline request handling. When the R session is busy, some requests are allowed to run")
      (kSessionHandleOfflineTimeoutMs,
      value<int>(&handleOfflineTimeoutMs_)->default_value(200),
      "Duration in millis before requests that can be handled offline are processed by the offline handler thread.");

   pAllow->add_options()
      ("allow-vcs-executable-edit",
      value<bool>(&allowVcsExecutableEdit_)->default_value(true),
      "Indicates whether or not to allow editing of VCS (Version Control Systems) executables.")
      ("allow-r-cran-repos-edit",
      value<bool>(&allowCRANReposEdit_)->default_value(true),
      "Indicates whether or not to allow editing of CRAN repositories.")
      ("allow-vcs",
      value<bool>(&allowVcs_)->default_value(true),
      "Indicates whether or not to allow the use of version control features.")
      ("allow-package-installation",
      value<bool>(&allowPackageInstallation_)->default_value(true),
      "Indicates whether or not to allow installation of packages from the packages pane.")
      ("allow-shell",
      value<bool>(&allowShell_)->default_value(true),
      "Indicates whether or not to allow access to the shell dialog.")
      ("allow-terminal-websockets",
      value<bool>(&allowTerminalWebsockets_)->default_value(true),
      "Indicates whether or not to allow connections to terminal sessions with websockets.")
      ("allow-file-downloads",
      value<bool>(&allowFileDownloads_)->default_value(true),
      "Indicates whether or not to allow file downloads from the files pane.")
      ("allow-file-uploads",
      value<bool>(&allowFileUploads_)->default_value(true),
      "Indicates whether or not to allow file uploads from the files pane.")
      ("allow-remove-public-folder",
      value<bool>(&allowRemovePublicFolder_)->default_value(true),
      "Indicates whether or not to allow removal of the user public folder.")
      ("allow-rpubs-publish",
      value<bool>(&allowRpubsPublish_)->default_value(true),
      "Indicates whether or not to allow publishing of content to external services.")
      ("allow-external-publish",
      value<bool>(&allowExternalPublish_)->default_value(true),
      "Indicates whether or not to allow publishing of content to external services.")
      ("allow-publish",
      value<bool>(&allowPublish_)->default_value(true),
      "Indicates whether or not to allow publishing of content.")
      ("allow-presentation-commands",
      value<bool>(&allowPresentationCommands_)->default_value(false),
      "Indicates whether or not to allow presentation commands.")
      ("allow-full-ui",
      value<bool>(&allowFullUI_)->default_value(true),
      "Indicates whether or not to allow full standalone UI mode.")
      ("allow-launcher-jobs",
      value<bool>(&allowLauncherJobs_)->default_value(true),
      "Indicates whether or not to allow running jobs via the Launcher.");

   pR->add_options()
      ("r-core-source",
      value<std::string>(&coreRSourcePath_)->default_value("R"),
      "Specifies the Core R source path.")
      ("r-modules-source",
      value<std::string>(&modulesRSourcePath_)->default_value("R/modules"),
      "Specifies the Modules R source path.")
      ("r-session-library",
      value<std::string>(&sessionLibraryPath_)->default_value("R/library"),
      "Specifies the R library path.")
      ("r-session-package-archives",
      value<std::string>(&sessionPackageArchivesPath_)->default_value("R/packages"),
      "Specifies the R package archives path.")
      ("r-libs-user",
      value<std::string>(&rLibsUser_)->default_value(""),
      "Specifies the R user library path.")
      ("r-cran-repos",
      value<std::string>(&rCRANUrl_)->default_value(""),
      "Specifies the default CRAN repository.")
      ("r-cran-repos-file",
      value<std::string>(&rCRANReposFile_)->default_value(core::system::xdg::systemConfigFile("repos.conf").getAbsolutePath()),
      "Specifies the path to a configuration file which contains default CRAN repositories.")
      ("r-cran-repos-url",
      value<std::string>(&rCRANReposUrl_)->default_value(""),
      "Specifies the URL to a configuration file which contains optional CRAN repositories.")
      ("r-auto-reload-source",
      value<bool>(&autoReloadSource_)->default_value(false),
      "Indicates whether or not to automatically reload R source if it changes during the session.")
      ("r-compatible-graphics-engine-version",
      value<int>(&rCompatibleGraphicsEngineVersion_)->default_value(14),
      "Specifies the maximum graphics engine version that this version of RStudio is compatible with.")
      ("r-resources-path",
      value<std::string>(&rResourcesPath_)->default_value("resources"),
      "Specifies the directory containing external resources.")
      ("r-shell-escape",
      value<bool>(&deprecatedRShellEscape_)->default_value(false),
      "Indicates whether or not to support shell escape.")
      ("r-home-dir-override",
      value<std::string>(&rHomeDirOverride_)->default_value(""),
      "Specifies the override for R_HOME (used for debug configurations).")
      ("r-doc-dir-override",
      value<std::string>(&rDocDirOverride_)->default_value(""),
      "Specifies the override for R_DOC_DIR (used for debug configurations).")
      ("r-restore-workspace",
      value<int>(&rRestoreWorkspace_)->default_value(kRestoreWorkspaceDefault),
      "If set, overrides the user/project restore workspace setting. Can be 0 (No), 1 (Yes), or 2 (Default).")
      ("r-run-rprofile",
      value<int>(&rRunRprofile_)->default_value(kRunRprofileDefault),
      "If set, overrides the user/project .Rprofile run setting. Can be 0 (No), 1 (Yes), or 2 (Default).");

   pLimits->add_options()
      ("limit-file-upload-size-mb",
      value<int>(&limitFileUploadSizeMb_)->default_value(0),
      "Sets a size limit in megabytes on files that are uploaded via the files pane.")
      ("limit-cpu-time-minutes",
      value<int>(&limitCpuTimeMinutes_)->default_value(0),
      "Sets a limit in minutes for the amount of time top level R computations may run before being interrupted.")
      ("limit-xfs-disk-quota",
      value<bool>(&limitXfsDiskQuota_)->default_value(false),
      "Indicates whether or not XFS quotas should be enforced when performing file operations via the files pane.");

   pExternal->add_options()
      ("external-rpostback-path",
      value<std::string>(&rpostbackPath_)->default_value(kDefaultPostbackPath),
      "Specifies the path to the rpostback executable.")
      ("external-consoleio-path",
      value<std::string>(&consoleIoPath_)->default_value("bin/consoleio.exe"),
      "Specifies the path to the consoleio executable (Windows-only).")
      ("external-gnudiff-path",
      value<std::string>(&gnudiffPath_)->default_value("bin/gnudiff"),
      "Specifies the path to gnudiff utilities (Windows-only).")
      ("external-gnugrep-path",
      value<std::string>(&gnugrepPath_)->default_value("bin/gnugrep"),
      "Specifies the path to gnugrep utilities (Windows-only).")
      ("external-msysssh-path",
      value<std::string>(&msysSshPath_)->default_value("bin/msys-ssh-1000-18"),
      "Specifies the path to msys_ssh utilities (Windows-only).")
      ("external-sumatra-path",
      value<std::string>(&sumatraPath_)->default_value("bin/sumatra"),
      "Specifies the path to SumatraPDF (Windows-only).")
      ("external-winutils-path",
      value<std::string>(&winutilsPath_)->default_value("bin/winutils"),
      "Specifies the path to Hadoop Winutils (Windows-only).")
      ("external-hunspell-dictionaries-path",
      value<std::string>(&hunspellDictionariesPath_)->default_value("resources/dictionaries"),
      "Specifies the path to hunspell dictionaries.")
      ("external-mathjax-path",
      value<std::string>(&mathjaxPath_)->default_value("resources/mathjax-27"),
      "Specifies the path to the mathjax library.")
      ("external-pandoc-path",
      value<std::string>(&pandocPath_)->default_value(kDefaultPandocPath),
      "Specifies the path to pandoc binaries.")
      ("external-libclang-path",
      value<std::string>(&libclangPath_)->default_value(kDefaultRsclangPath),
      "Specifies the path to the libclang shared library")
      ("external-libclang-headers-path",
      value<std::string>(&libclangHeadersPath_)->default_value("resources/libclang/builtin-headers"),
      "Specifies the path to the libclang builtin headers.")
      ("external-winpty-path",
      value<std::string>(&winptyPath_)->default_value("bin"),
      "Specifies the path to winpty binaries.");

   pGit->add_options()
      ("git-commit-large-file-size",
      value<int>(&gitCommitLargeFileSize_)->default_value(5242880),
      "Warns when attempting to commit files larger than this size (in bytes; set 0 to disable).");

   pUser->add_options()
      (kUserIdentitySessionOption "," kUserIdentitySessionOptionShort,
      value<std::string>(&userIdentity_)->default_value(core::system::username()),
      "The user identity for the session.")
      (kShowUserIdentitySessionOption,
      value<bool>(&showUserIdentity_)->default_value(true),
      "Indicates whether or not to show the user identity in the session UI.")
      (kProjectSessionOption "," kProjectSessionOptionShort,
      value<std::string>(&projectId_)->default_value(""),
      "Specifies the active project.")
      (kScopeSessionOption "," kScopeSessionOptionShort,
      value<std::string>(&scopeId_)->default_value(""),
      "Specifies the session identifier.")
      ("launcher-token",
      value<std::string>(&launcherToken_)->default_value(""),
      "Specifies the token identifying the session launcher.");

   pMisc->add_options();

   FilePath defaultConfigPath = core::system::xdg::findSystemConfigFile("rsession configuration", "rsession.conf");
   std::string configFile = defaultConfigPath.exists() ?
      defaultConfigPath.getAbsolutePath() : "";
   return program_options::OptionsDescription("rsession", configFile);
}

public:
   bool runTests() const { return runTests_; }
   std::string runScript() const { return runScript_; }
   bool verifyInstallation() const { return verifyInstallation_; }
   bool version() const { return version_; }
   std::string programMode() const { return programMode_; }
   bool logStderr() const { return logStderr_; }
   std::string docsURL() const { return docsURL_; }
   std::string wwwLocalPath() const { return wwwLocalPath_; }
   core::FilePath wwwSymbolMapsPath() const { return core::FilePath(wwwSymbolMapsPath_); }
   std::string wwwPort() const { return wwwPort_; }
   std::string wwwAddress() const { return wwwAddress_; }
   bool standalone() const { return standalone_; }
   bool verifySignatures() const { return verifySignatures_; }
   bool wwwReusePorts() const { return wwwReusePorts_; }
   int timeoutMinutes() const { return timeoutMinutes_; }
   bool timeoutSuspend() const { return timeoutSuspend_; }
   int disconnectedTimeoutMinutes() const { return disconnectedTimeoutMinutes_; }
   core::FilePath preflightScriptPath() const { return core::FilePath(preflightScriptPath_); }
   bool createPublicFolder() const { return createPublicFolder_; }
   bool createProfile() const { return createProfile_; }
   bool rProfileOnResumeDefault() const { return rProfileOnResumeDefault_; }
   int saveActionDefault() const { return saveActionDefault_; }
   std::string defaultWorkingDir() const { return defaultWorkingDir_; }
   std::string deprecatedDefaultProjectDir() const { return deprecatedDefaultProjectDir_; }
   bool showHelpHome() const { return showHelpHome_; }
   std::string defaultConsoleTerm() const { return defaultConsoleTerm_; }
   bool defaultCliColorForce() const { return defaultCliColorForce_; }
   bool quitChildProcessesOnExit() const { return quitChildProcessesOnExit_; }
   std::string firstProjectTemplatePath() const { return firstProjectTemplatePath_; }
   std::string defaultRSConnectServer() const { return defaultRSConnectServer_; }
   std::string terminalPort() const { return terminalPort_; }
   int webSocketPingInterval() const { return webSocketPingSeconds_; }
   int webSocketConnectTimeout() const { return webSocketConnectTimeout_; }
   int webSocketLogLevel() const { return webSocketLogLevel_; }
   int webSocketHandshakeTimeoutMs() const { return webSocketHandshakeTimeoutMs_; }
   bool packageOutputInPackageFolder() const { return packageOutputToPackageFolder_; }
   std::string rootPath() const { return rootPath_; }
   bool useSecureCookies() const { return useSecureCookies_; }
   rstudio::core::http::Cookie::SameSite sameSite() const { return sameSite_; }
   bool restrictDirectoryView() const { return restrictDirectoryView_; }
   std::string directoryViewAllowList() const { return directoryViewAllowList_; }
   std::string ephemeralEnvVars() const { return ephemeralEnvVars_; }
   bool suspendOnIncompleteStatement() const { return suspendOnIncompleteStatement_; }
   bool asyncRpcEnabled() const { return asyncRpcEnabled_; }
   int asyncRpcTimeoutMs() const { return asyncRpcTimeoutMs_; }
   bool handleOfflineEnabled() const { return handleOfflineEnabled_; }
   int handleOfflineTimeoutMs() const { return handleOfflineTimeoutMs_; }
   bool allowVcsExecutableEdit() const { return allowVcsExecutableEdit_; }
   bool allowCRANReposEdit() const { return allowCRANReposEdit_; }
   bool allowVcs() const { return allowVcs_; }
   bool allowPackageInstallation() const { return allowPackageInstallation_; }
   bool allowShell() const { return allowShell_; }
   bool allowTerminalWebsockets() const { return allowTerminalWebsockets_; }
   bool allowFileDownloads() const { return allowFileDownloads_; }
   bool allowFileUploads() const { return allowFileUploads_; }
   bool allowRemovePublicFolder() const { return allowRemovePublicFolder_; }
   bool allowRpubsPublish() const { return allowRpubsPublish_; }
   bool allowExternalPublish() const { return allowExternalPublish_; }
   bool allowPublish() const { return allowPublish_; }
   bool allowPresentationCommands() const { return allowPresentationCommands_; }
   bool allowFullUI() const { return allowFullUI_; }
   bool allowLauncherJobs() const { return allowLauncherJobs_; }
   core::FilePath coreRSourcePath() const { return core::FilePath(coreRSourcePath_); }
   core::FilePath modulesRSourcePath() const { return core::FilePath(modulesRSourcePath_); }
   core::FilePath sessionLibraryPath() const { return core::FilePath(sessionLibraryPath_); }
   core::FilePath sessionPackageArchivesPath() const { return core::FilePath(sessionPackageArchivesPath_); }
   std::string rLibsUser() const { return rLibsUser_; }
   std::string rCRANUrl() const { return rCRANUrl_; }
   std::string rCRANReposFile() const { return rCRANReposFile_; }
   std::string rCRANReposUrl() const { return rCRANReposUrl_; }
   bool autoReloadSource() const { return autoReloadSource_; }
   int rCompatibleGraphicsEngineVersion() const { return rCompatibleGraphicsEngineVersion_; }
   core::FilePath rResourcesPath() const { return core::FilePath(rResourcesPath_); }
   bool deprecatedRShellEscape() const { return deprecatedRShellEscape_; }
   std::string rHomeDirOverride() const { return rHomeDirOverride_; }
   std::string rDocDirOverride() const { return rDocDirOverride_; }
   int rRestoreWorkspace() const { return rRestoreWorkspace_; }
   int rRunRprofile() const { return rRunRprofile_; }
   int limitFileUploadSizeMb() const { return limitFileUploadSizeMb_; }
   int limitCpuTimeMinutes() const { return limitCpuTimeMinutes_; }
   bool limitXfsDiskQuota() const { return limitXfsDiskQuota_; }
   core::FilePath rpostbackPath() const { return core::FilePath(rpostbackPath_); }
   core::FilePath consoleIoPath() const { return core::FilePath(consoleIoPath_); }
   core::FilePath gnudiffPath() const { return core::FilePath(gnudiffPath_); }
   core::FilePath gnugrepPath() const { return core::FilePath(gnugrepPath_); }
   core::FilePath msysSshPath() const { return core::FilePath(msysSshPath_); }
   core::FilePath sumatraPath() const { return core::FilePath(sumatraPath_); }
   core::FilePath winutilsPath() const { return core::FilePath(winutilsPath_); }
   core::FilePath hunspellDictionariesPath() const { return core::FilePath(hunspellDictionariesPath_); }
   core::FilePath mathjaxPath() const { return core::FilePath(mathjaxPath_); }
   core::FilePath pandocPath() const { return core::FilePath(pandocPath_); }
   core::FilePath libclangPath() const { return core::FilePath(libclangPath_); }
   core::FilePath libclangHeadersPath() const { return core::FilePath(libclangHeadersPath_); }
   core::FilePath winptyPath() const { return core::FilePath(winptyPath_); }
   int gitCommitLargeFileSize() const { return gitCommitLargeFileSize_; }
   std::string userIdentity() const { return userIdentity_; }
   bool showUserIdentity() const { return showUserIdentity_; }
   std::string launcherToken() const { return launcherToken_; }


protected:
   bool runTests_;
   std::string runScript_;
   bool verifyInstallation_;
   bool version_;
   std::string programMode_;
   bool logStderr_;
   std::string docsURL_;
   std::string wwwLocalPath_;
   std::string wwwSymbolMapsPath_;
   std::string wwwPort_;
   std::string wwwAddress_;
   bool standalone_;
   bool verifySignatures_;
   bool wwwReusePorts_;
   int timeoutMinutes_;
   bool timeoutSuspend_;
   int disconnectedTimeoutMinutes_;
   std::string preflightScriptPath_;
   bool createPublicFolder_;
   bool createProfile_;
   bool rProfileOnResumeDefault_;
   int saveActionDefault_;
   std::string defaultWorkingDir_;
   std::string deprecatedDefaultProjectDir_;
   bool showHelpHome_;
   std::string defaultConsoleTerm_;
   bool defaultCliColorForce_;
   bool quitChildProcessesOnExit_;
   std::string firstProjectTemplatePath_;
   std::string defaultRSConnectServer_;
   std::string terminalPort_;
   int webSocketPingSeconds_;
   int webSocketConnectTimeout_;
   int webSocketLogLevel_;
   int webSocketHandshakeTimeoutMs_;
   bool packageOutputToPackageFolder_;
   std::string rootPath_;
   bool useSecureCookies_;
   rstudio::core::http::Cookie::SameSite sameSite_;
   bool restrictDirectoryView_;
   std::string directoryViewAllowList_;
   std::string ephemeralEnvVars_;
   bool suspendOnIncompleteStatement_;
   bool asyncRpcEnabled_;
   int asyncRpcTimeoutMs_;
   bool handleOfflineEnabled_;
   int handleOfflineTimeoutMs_;
   bool allowVcsExecutableEdit_;
   bool allowCRANReposEdit_;
   bool allowVcs_;
   bool allowPackageInstallation_;
   bool allowShell_;
   bool allowTerminalWebsockets_;
   bool allowFileDownloads_;
   bool allowFileUploads_;
   bool allowRemovePublicFolder_;
   bool allowRpubsPublish_;
   bool allowExternalPublish_;
   bool allowPublish_;
   bool allowPresentationCommands_;
   bool allowFullUI_;
   bool allowLauncherJobs_;
   std::string coreRSourcePath_;
   std::string modulesRSourcePath_;
   std::string sessionLibraryPath_;
   std::string sessionPackageArchivesPath_;
   std::string rLibsUser_;
   std::string rCRANUrl_;
   std::string rCRANReposFile_;
   std::string rCRANReposUrl_;
   bool autoReloadSource_;
   int rCompatibleGraphicsEngineVersion_;
   std::string rResourcesPath_;
   bool deprecatedRShellEscape_;
   std::string rHomeDirOverride_;
   std::string rDocDirOverride_;
   int rRestoreWorkspace_;
   int rRunRprofile_;
   int limitFileUploadSizeMb_;
   int limitCpuTimeMinutes_;
   bool limitXfsDiskQuota_;
   std::string rpostbackPath_;
   std::string consoleIoPath_;
   std::string gnudiffPath_;
   std::string gnugrepPath_;
   std::string msysSshPath_;
   std::string sumatraPath_;
   std::string winutilsPath_;
   std::string hunspellDictionariesPath_;
   std::string mathjaxPath_;
   std::string pandocPath_;
   std::string libclangPath_;
   std::string libclangHeadersPath_;
   std::string winptyPath_;
   int gitCommitLargeFileSize_;
   std::string userIdentity_;
   bool showUserIdentity_;
   std::string projectId_;
   std::string scopeId_;
   std::string launcherToken_;
};

} // namespace session
} // namespace rstudio


#endif // SESSION_SESSION_OPTIONS_GEN_HPP
