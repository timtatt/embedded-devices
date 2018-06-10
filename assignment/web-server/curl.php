<?php
class SCCurl {
	function __construct($url) {
		$this->url = $url;
		$this->headers = array();
		$this->user = '';
	}
	function headers($headers) {
		$this->headers += $headers;
	}
	function user($user) {
		$this->user = $user;
	}
	function get($params) {
		$ch = curl_init();

		curl_setopt($ch, CURLOPT_URL, $this->url . '?' . http_build_query($params));
		curl_setopt($ch, CURLOPT_POST, 0);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

		if (!empty($this->user)) {
			curl_setopt($ch, CURLOPT_USERPWD, $this->user);
			curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
		}

		if (count($this->headers) > 0) {
			curl_setopt($ch, CURLOPT_HTTPHEADER, $this->headers);
		}

		$response = curl_exec($ch);
		curl_close($ch);

		return $response;
	}
	function post($params, $json = false) {
		$ch = curl_init();

		$body = $json == true ? json_encode($params) : http_build_query($params);

		curl_setopt($ch, CURLOPT_URL, $this->url);
		curl_setopt($ch, CURLOPT_POST, 1);
		curl_setopt($ch, CURLOPT_POSTFIELDS, $body);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

		if (!empty($this->user)) {
			curl_setopt($ch, CURLOPT_USERPWD, $this->user);
			curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
		}

		if (count($this->headers) > 0) {
			curl_setopt($ch, CURLOPT_HTTPHEADER, $this->headers);
		}

		$response = curl_exec($ch);
		curl_close($ch);

		return $response;
	}
}