#!/usr/bin/env bash

if [[ $TRAVIS_BRANCH == 'master' ]] ; then
  cd $TRAVIS_BUILD_DIR
  chmod +x generateDocumentationAndDeploy.sh
  ./generateDocumentationAndDeploy.sh
fi