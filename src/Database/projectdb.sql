--
-- PostgreSQL database cluster dump
--

SET default_transaction_read_only = off;

SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;

--
-- Roles
--

CREATE ROLE anton;
ALTER ROLE anton WITH SUPERUSER INHERIT CREATEROLE CREATEDB LOGIN REPLICATION NOBYPASSRLS PASSWORD 'md5e2fe2a1ccbfce7494049c78d3d1a0eed';
CREATE ROLE postgres;
ALTER ROLE postgres WITH SUPERUSER INHERIT CREATEROLE CREATEDB LOGIN REPLICATION BYPASSRLS PASSWORD 'md57cc79babeb8a662557ad3c16b70e7128';
CREATE ROLE toha;
ALTER ROLE toha WITH SUPERUSER INHERIT CREATEROLE CREATEDB LOGIN NOREPLICATION NOBYPASSRLS PASSWORD 'md51fa2173b9060da6ca40b06a6064e7255';
CREATE ROLE vita;
ALTER ROLE vita WITH SUPERUSER INHERIT CREATEROLE CREATEDB LOGIN REPLICATION NOBYPASSRLS PASSWORD 'md580da49189708ba2bcf77a1d4387e2d86';






--
-- Database creation
--

CREATE DATABASE anton WITH TEMPLATE = template0 OWNER = toha;
CREATE DATABASE store WITH TEMPLATE = template0 OWNER = toha;
REVOKE CONNECT,TEMPORARY ON DATABASE template1 FROM PUBLIC;
GRANT CONNECT ON DATABASE template1 TO PUBLIC;
CREATE DATABASE toha WITH TEMPLATE = template0 OWNER = postgres;
CREATE DATABASE vita WITH TEMPLATE = template0 OWNER = toha;


\connect anton

SET default_transaction_read_only = off;

--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.10
-- Dumped by pg_dump version 9.6.10

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


--
-- PostgreSQL database dump complete
--

\connect postgres

SET default_transaction_read_only = off;

--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.10
-- Dumped by pg_dump version 9.6.10

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: DATABASE postgres; Type: COMMENT; Schema: -; Owner: postgres
--

COMMENT ON DATABASE postgres IS 'default administrative connection database';


--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


--
-- PostgreSQL database dump complete
--

\connect store

SET default_transaction_read_only = off;

--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.10
-- Dumped by pg_dump version 9.6.10

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: computers; Type: TABLE; Schema: public; Owner: toha
--

CREATE TABLE public.computers (
    id integer NOT NULL,
    type text,
    count integer
);


ALTER TABLE public.computers OWNER TO toha;

--
-- Name: computers_id_seq; Type: SEQUENCE; Schema: public; Owner: toha
--

CREATE SEQUENCE public.computers_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.computers_id_seq OWNER TO toha;

--
-- Name: computers_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: toha
--

ALTER SEQUENCE public.computers_id_seq OWNED BY public.computers.id;


--
-- Name: computers id; Type: DEFAULT; Schema: public; Owner: toha
--

ALTER TABLE ONLY public.computers ALTER COLUMN id SET DEFAULT nextval('public.computers_id_seq'::regclass);


--
-- Data for Name: computers; Type: TABLE DATA; Schema: public; Owner: toha
--

COPY public.computers (id, type, count) FROM stdin;
1	spot_laptop	5
2	swing_laptop	5
3	ultra_laptop	5
4	spot_desktop	5
5	swing_desktop	5
\.


--
-- Name: computers_id_seq; Type: SEQUENCE SET; Schema: public; Owner: toha
--

SELECT pg_catalog.setval('public.computers_id_seq', 5, true);


--
-- Name: computers computers_pkey; Type: CONSTRAINT; Schema: public; Owner: toha
--

ALTER TABLE ONLY public.computers
    ADD CONSTRAINT computers_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--

\connect template1

SET default_transaction_read_only = off;

--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.10
-- Dumped by pg_dump version 9.6.10

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: DATABASE template1; Type: COMMENT; Schema: -; Owner: postgres
--

COMMENT ON DATABASE template1 IS 'default template for new databases';


--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


--
-- PostgreSQL database dump complete
--

\connect toha

SET default_transaction_read_only = off;

--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.10
-- Dumped by pg_dump version 9.6.10

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: request; Type: TABLE; Schema: public; Owner: anton
--

CREATE TABLE public.request (
    name text,
    ipn text,
    description text,
    status text,
    date date
);


ALTER TABLE public.request OWNER TO anton;

--
-- Data for Name: request; Type: TABLE DATA; Schema: public; Owner: anton
--

COPY public.request (name, ipn, description, status, date) FROM stdin;
dsfsd	sdfsdf	sdf	Done!	\N
sdafasdf	asdfsadf	asadfasdf	Done!	\N
sdfsd	sdfsdf	sdfsd	Done!	2018-10-08
sdf	sdf	sdaf	In progress!	2018-10-09
\.


--
-- PostgreSQL database dump complete
--

\connect vita

SET default_transaction_read_only = off;

--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.10
-- Dumped by pg_dump version 9.6.10

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: license; Type: TABLE; Schema: public; Owner: anton
--

CREATE TABLE public.license (
    name text,
    developer text
);


ALTER TABLE public.license OWNER TO anton;

--
-- Name: request; Type: TABLE; Schema: public; Owner: anton
--

CREATE TABLE public.request (
    name text,
    ipn text,
    description text,
    status text,
    date date
);


ALTER TABLE public.request OWNER TO anton;

--
-- Name: software; Type: TABLE; Schema: public; Owner: anton
--

CREATE TABLE public.software (
    name text,
    license text NOT NULL,
    developer text
);


ALTER TABLE public.software OWNER TO anton;

--
-- Data for Name: license; Type: TABLE DATA; Schema: public; Owner: anton
--

COPY public.license (name, developer) FROM stdin;
GPL	GNU_Project
MIT	MIT_University
\.


--
-- Data for Name: request; Type: TABLE DATA; Schema: public; Owner: anton
--

COPY public.request (name, ipn, description, status, date) FROM stdin;
dsfsd	sdfsdf	sdf	Done!	\N
sdafasdf	asdfsadf	asadfasdf	Done!	\N
sdfsd	sdfsdf	sdfsd	Done!	2018-10-08
sdf	sdf	sdaf	In progress!	2018-10-09
sadfs	sadf	sdaf	Done!	2018-10-09
sad	asd	asd	Done!	2018-10-10
sdf	sdf	sdf	In progress!	2018-10-09
sdf	sdfsdf	sdf	Done!	2018-10-14
sadf	sdaf	asdf	Done!	2018-10-14
sdas	asdasd	asd	Done!	2018-10-14
\.


--
-- Data for Name: software; Type: TABLE DATA; Schema: public; Owner: anton
--

COPY public.software (name, license, developer) FROM stdin;
\.


--
-- PostgreSQL database dump complete
--

--
-- PostgreSQL database cluster dump complete
--

